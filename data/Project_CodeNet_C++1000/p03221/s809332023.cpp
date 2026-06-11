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

map<int, map<long long, int>> mp;
int P[100000+2] = {0};
long long Y[100000+2] = {0};

int main(int argc, char* argv[]){
	int N, M;

	cin >> N >> M;

	for(int i=1; i<=M; i++){
		int p;
		long long y;
		cin >> p >> y;
		P[i] = p; Y[i] = y;
		if(mp.count(p)==0){
			map<long long, int> m;
			m[y] = -1;
			mp[p] = m;
		}
		else{
			mp[p][y] = -1;
		}
	}

	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		auto& m = itr->second;
		int i = 1;
		for(auto it = m.begin(); it != m.end(); it++){
			auto& k = it->first;
			m[k] = i;
			i++;
		}
	}
	for(int i = 1; i <= M; i++){
		int p = P[i];
		long long y = Y[i];
		printf("%06d%06d\n", p, mp[p][y]);
	}
	return 0;
}