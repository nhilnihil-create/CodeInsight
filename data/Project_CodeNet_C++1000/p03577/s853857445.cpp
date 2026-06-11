#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	string s;
	cin>>s;
	for(int i=0;i<s.length()-7;i++){
		if(s.substr(i,1)=="F"&&s.substr(i+1,1)=="E"&&s.substr(i+2,1)=="S"&&s.substr(i+3,1)=="T"&&s.substr(i+4,1)=="I"&&s.substr(i+5,1)=="V"&&s.substr(i+6,1)=="A"&&s.substr(i+7,1)=="L"){
			s.erase(s.length()-8,8);
			break;
		}
	}
	cout<<s<<endl;
	return 0;
}

