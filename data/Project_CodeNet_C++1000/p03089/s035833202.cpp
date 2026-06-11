#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

void printVec(vector<int> vec){
	for(int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<endl;
	}
	return ;
}

int main()
{
	int n;
	vector<int> vec1,vec2;
	bool isPossible;
	cin>>n;
	for(int i = 0; i < n; i++){
		int num;
		cin>>num;
		vec1.push_back(num);
	}
	do{
		isPossible = false;
		for(int i = vec1.size() - 1; i >= 0; i--){
			if( vec1[i] == i + 1){
				vec2.insert(vec2.begin(),vec1[i]);
				vec1.erase(vec1.begin() + i);
				isPossible = true;
				break;
			}
		}
	}while(vec1.size() > 0 && isPossible == true);

	if( vec2.size() == n){
		printVec(vec2);
	}else{
		cout<<-1<<endl;
	}
	return 0;
}

