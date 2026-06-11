#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

long long lpow(int x, int y){
	long long ret = 1;
	for(int i = 0; i < y; i++){
		ret = ret*x;
	}
	return ret;
}

void dfs(vector<int> &v, int len, long long &count, long long n){
	if(v.size()==len){
		long long s = 0;
		int ret = 1, c7 = 0, c5 = 0, c3 = 0;
		for(int i = 0; i < v.size(); i++){
			int u = v[i];
			s  += (int) u*lpow(10, i);
			if(u != 7 && u != 5 && u != 3){
				ret = 0;
				break;
			}
			if(u == 7){ c7++; }
			if(u == 5){ c5++; }
			if(u == 3){ c3++; }
		}
		if(s > n) return;
		if(ret == 1 && c7 > 0 && c5 > 0 && c3 > 0){
			count++;
		}
		return;
	}

	for(int i=3; i<9; i+=2){ //i=3, 5, 7
		v.push_back(i);
		dfs(v, len, count, n);
		v.pop_back();
	}
}

int main(int argc, char* argv[]){
	long long N;

	cin >> N ;

	long long ans = 0;
	for(int len = 3; len<=9; len++){
		vector<int> v;
		dfs(v, len, ans, N);
		v.clear();
	}
	cout << ans << endl ;
	return 0;
}