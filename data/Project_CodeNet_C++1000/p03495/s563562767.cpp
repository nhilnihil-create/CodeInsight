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

int N, K;
map<int, int> A;
vector<pair<int, int>> B;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i=0; i<N; i++){
		int v;
		cin >> v;
		if(A.count(v)==0){
			A[v] = 1;
		}
		else{
			A[v]++;
		}
	}

	for(auto itr = A.begin(); itr != A.end(); itr++){
		int k = itr->first;
		int v = itr->second;
		B.push_back(make_pair(v, k));
	}
	sort(B.begin(), B.end());

	int ans = 0;
	if(B.size() <= K){
		ans = 0;
	}
	else{
		for(int i=0; i<B.size() - K; i++){
			ans += B[i].first;
		}
	}
	printf("%d\n", ans);
	return 0;
}