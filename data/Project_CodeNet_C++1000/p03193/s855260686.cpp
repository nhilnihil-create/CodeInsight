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

typedef unsigned long long LL;

LL N;
vector<LL> D;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, H, W;
	cin >> N >> H >> W;
	LL ans = 0;
	for(int i=0; i<N; i++){
		LL a, b;
		cin >> a >> b;
		if(a >= H && b >= W){
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
