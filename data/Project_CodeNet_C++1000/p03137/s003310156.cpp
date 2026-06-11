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
	int N, M;
	cin >> N >> M;
	vector<int> v;
	vector<long long> dist;

	if(N >= M){
		cout << 0 << endl;
		return 0;
	}

	for(int i = 1; i <= M; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size() - 1; i++){
		long long d = v[i + 1] - v[i];
		dist.push_back(d);
	}

	sort(dist.begin(), dist.end());

	for(int i=1; i<=N-1; i++){
		dist.pop_back();
	}

	long long ans = 0;
	for(int i=0; i<dist.size(); i++){
		ans += dist[i];
	}

	cout << ans << endl ;
	return 0;
}