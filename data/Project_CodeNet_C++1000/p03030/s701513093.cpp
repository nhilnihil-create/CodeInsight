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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	map<string, vector<pair<int, int>>> M;

	for(int i=1; i<=N; i++){
		string s; cin >> s;
		int p; cin >> p;
		if(M.count(s) == 0){
			vector<pair<int, int>> v;
			v.push_back(make_pair(p, i));
			M[s] = v;
		}
		else{
			M[s].push_back(make_pair(p, i));
		}
	}
	for(auto itr = M.begin(); itr != M.end(); itr++){
		string k = itr->first;
		auto v = itr->second;
		sort(v.begin(), v.end());
		for(int i=v.size()-1; i>=0; i--){
			auto p = v[i];
			printf("%d\n", p.second);
		}
	}
	return 0;
}