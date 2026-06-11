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
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N;
	map<int, int> mp;

	cin >> N;
	for(int i = 0; i < N; i++){
		int v;
		cin >> v;
		if(mp.count(v) == 0){
			mp[v] = 1;
		}
		else{
			mp[v]++;
		}
	}
	int ans = 0;
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		int k = itr->first;
		int v = itr->second;
		if(v > k){
			ans += (v - k);
		}
		else if(v < k){
			ans += v;
		}
	}
	printf("%d\n", ans);
	return 0;
}