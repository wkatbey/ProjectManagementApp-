//
//  ProjectType.hpp
//  ProjectManagementApplication
//
//  Created by Wassim Katbey on 12/29/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef ProjectType_H
#define ProjectType_H
#include "toolType.h"
#include <map>


class projectType : public toolType {
  
    friend ostream& operator<<(ostream& osObject, projectType project);
    friend istream& operator>>(istream& isObject, projectType project);

public:
    
    enum projectInfo {INCOMPLETE, COMPLETE, ABANDONED};
    
    projectType(string name = "", string desc = "", projectInfo i = INCOMPLETE,
                int start[6] = 0, int end[6] = 0);
    
    void setProjectName(string name);
    void writeDescription(string desc);
    
    void setStartDate(int start[6]);
    void setEndDate(int end[6]);

    void completeProject();
    void abandonProject();
    
    void employ(toolType employee);
    void dismiss(toolType employee);
   
	void increasePriority();
	void decreasePriority();
    
    statusType getEmployeeStatus(toolType employee) const;
    projectInfo getProgress() const;
    
    string getStartDate() const;
    string getEndDate() const;
    
    string getDescription() const;

	int getPriority() const;
    
    void printEmployeeDatabase();
    void printProjectInfo();
    
    
private:

	void setProjectIncomplete();
    
    string projectName;
	string description;
    projectInfo progress;
    
    string startDate;
    string endDate;

	int priority;

    map<string, toolType> employeeMap;
    
};












#endif /* ProjectType_hpp */
