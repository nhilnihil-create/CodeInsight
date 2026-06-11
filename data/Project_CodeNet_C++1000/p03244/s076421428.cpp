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

long long N;
long long v[100000+2] = {0};

map<long long, int> mpodd;
map<long long, int> mpeven;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> v[i];
	}
	for(int i=1; i<=N; i++){
		if((i % 2) == 1){
			if(mpodd.count(v[i]) == 0){
				mpodd[v[i]] = 1;
			}
			else{
				mpodd[v[i]]++;
			}
		}
		else{
			if(mpeven.count(v[i]) == 0){
				mpeven[v[i]] = 1;
			}
			else{
				mpeven[v[i]]++;
			}
		}
	}
	int odd_max = 0, even_max = 0;
	long long odd_key = 0, even_key = 0;
	vector<int> vo, ve;
	for(auto itr = mpodd.begin(); itr != mpodd.end(); itr++){
		long long key = itr->first;
		int val = itr->second;
		vo.push_back(val);
		if(odd_max < val){
			odd_key = key;
			odd_max = val;
		}
	}
	for(auto itr = mpeven.begin(); itr != mpeven.end(); itr++){
		long long key = itr->first;
		int val = itr->second;
		ve.push_back(val);
		if(even_max < val){
			even_key = key;
			even_max = val;
		}
	}

	sort(vo.begin(), vo.end());
	sort(ve.begin(), ve.end());

	int ans = 0;
	int osz = (int)vo.size();
	int esz = (int)ve.size();
	int o1, o2, e1, e2;
	o1 = vo[osz-1], e1 = ve[esz-1];
	if(osz == 1){
		o2 = 0;
	}
	else{
		o2 = vo[osz-2];
	}
	if(esz == 1){
		e2 = 0;
	}
	else{
		e2 = ve[esz-2];
	}
	int a1, a2, a3, a4;
	if(odd_key == even_key){
		a1 = (N/2) - o1 + (N/2) - e2;
		a2 = (N/2) - o2 + (N/2) - e1;
		ans = min(a1, a2);
	}
	else{
		ans = (N/2) - odd_max;
		ans += ((N/2) - even_max);
	}
	printf("%d\n", ans);
	return 0;
}