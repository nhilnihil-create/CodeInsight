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

long long N, M;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	long long oneshot = 100 * (N - M) + 1900 * M;
	long long t = 1;
	for(int i=1; i<=M; i++){
		t *= 2;
	}
	long long ans = oneshot * t;
	printf("%lld\n", ans);
	return 0;
}