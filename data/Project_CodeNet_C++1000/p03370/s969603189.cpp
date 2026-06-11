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

	LL N, X;
	cin >> N >> X;
	vector<LL> M;

	LL mst = 0;
	for(int i=0; i<N; i++){
		LL m;
		cin >> m;
		mst += m;
		M.push_back(m);
	}

	LL rem = X - mst;
	sort(M.begin(), M.end());
	LL ans = rem / M[0];
	printf("%lld\n", ans+N);
	return 0;
}

