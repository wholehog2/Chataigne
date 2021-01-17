/*
  ==============================================================================

    DampingFilter.h
    Created: 8 Dec 2020 11:36:15am
    Author:  bkupe

  ==============================================================================
*/

#pragma once

#include "../../MappingFilter.h"

class DampingFilter :
	public MappingFilter
{
public:
	DampingFilter(var params);
	~DampingFilter();

	FloatParameter* force;
	FloatParameter* friction;

	HashMap<Parameter *, var> previousSpeedsMap;

	double timeAtLastUpdate;
	const float precision = .00001f;

	void setupParametersInternal() override;
	Parameter* setupSingleParameterInternal(Parameter* source) override;
	bool processSingleParameterInternal(Parameter* source, Parameter* out) override;

	String getTypeString() const override { return "Damping"; }
};