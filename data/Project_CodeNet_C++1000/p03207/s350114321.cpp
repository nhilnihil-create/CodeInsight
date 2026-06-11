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

	LL N;
	cin >> N;
	vector<LL> P;
	for(int i=0; i<N; i++){
		LL p;
		cin >> p;
		P.push_back(p);
	}
	sort(P.begin(), P.end());

	LL ans = 0;
	for(int i=0; i<N; i++){
		if(i == N-1){
			ans += P[i]/2;
		}
		else{
			ans += P[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

