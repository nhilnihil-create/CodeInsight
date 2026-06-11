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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL K, A, B;
	cin >> K >> A >> B;
	LL ans = 0;

	if(A >= B - 1){
		ans = K+1;
		printf("%lld\n", ans);
		return 0;
	}

    if(K <= A - 1 || K == A){
		ans = K+1;
		printf("%lld\n", ans);
		return 0;
	}

	K -= (A - 1);
	ans = A;
	LL k = K / 2;
	ans += ((B - A) * k);
	LL r = K % 2;
	if(r != 0){
		ans++;
	}

	printf("%lld\n", ans);
	return 0;
}
