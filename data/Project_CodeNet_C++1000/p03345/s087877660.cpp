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
long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long A, B, C, K;
	cin >> A >> B >> C >> K;
	long long ans = 0;
	if((K % 2) == 1){
		ans = B - A;
	}
	else{
		ans = A -B;
	}
	printf("%lld\n", ans);
	return 0;
}

