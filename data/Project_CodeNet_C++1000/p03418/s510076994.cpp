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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);

LL N, K;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;

	int a, b, q, r;
	LL ans = 0;

	if(K == 0){
		printf("%lld\n", N*N);
		return 0;
	}

	for(b = K + 1; b<=N; b++){
		for(q = 0; ; q++){
			if(b*q > N){
				break;
			}
			r = N - (b*q);
			if(r >= b){
				r = b - 1;
			}
			if(r >= K){
				ans += (r - K + 1);
			}
		}
	}

	printf("%lld\n", ans);
	return 0;
}