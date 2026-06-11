#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int DP[(1 << 26)] = {};

//map<int, int> m;
//map<int, int>::iterator ite;

int main(){
	
	string str;
	cin >> str;
	
	for(int i = 0; i < (1 << 26); i++){
		DP[i] = str.size();
	}
	
	DP[0] = 0;
	int num = 0;
	for(int i = 0; i < str.size(); i++){
		num ^= (1 << (str[i] - 'a'));
		int res = DP[num] + 1;
		for(int j = 0; j < 26; j++){
			int state = (num ^ (1 << j));
			res = min(res, DP[state] + 1);
		}
		DP[num] = min(DP[num], res);
	}
	
	cout << max(DP[num], 1) << endl;
	
	return 0;
}
