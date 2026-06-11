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

int main(int argc, char* argv[]){
	int N, K;
	cin >> N >> K;
	vector<long long> v;

	for(int i = 1; i <= N; i++){
		long long h;
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(), v.end());

	long long d = 0;
	for(int i = 0; i <= v.size() - K; i++){
		long long h = v[i + K - 1] - v[i];
		if(i == 0 ) d = h;
		else if(h < d){
			d = h;
		}
	}
	cout << d << endl ;
	return 0;
}