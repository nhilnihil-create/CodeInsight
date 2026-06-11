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

int N;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	long long J = 0, B = 0;
	for(int i=0; i<N; i++){
		string x, u;
		cin >> x >> u;
		if(u == "JPY"){
			J += atoll(x.c_str());
		}
		else{
			string t;
			for(int j=0; j<x.size(); j++){
				if(x[j] != '.'){
					t.push_back(x[j]);
				}
			}
			B += atoll(t.c_str());
		}
	}
	long double ans = 0.0;
	ans += J;
	ans += (B/(10000.0))*38.0 ;
	printf("%.12Lf\n", ans);
	return 0;
}