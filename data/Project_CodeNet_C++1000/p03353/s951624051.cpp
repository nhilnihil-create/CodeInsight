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
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;


int main()
{
	int k;
	string str;
	cin >> str;
	cin >> k;
	int n = str.length();
	set<string> strMap;
	vector<string> strVec;
	//cout << str.substr(1, 2) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= (n-i); j++) {
			//cout << i << " " << j << " "<<str.substr(i, j) << endl;
			if(strVec.size() >= k && strVec[k-1] < str.substr(i,j)){
				break;
			}
			if( strMap.count(str.substr(i,j)) == 0){
				strMap.insert(str.substr(i, j));
				strVec.push_back(str.substr(i,j));
			}
			sort(strVec.begin(),strVec.end());
		}
	}
	sort(strVec.begin(), strVec.end());
	cout << strVec[k-1] << endl;
	return 0;
}
