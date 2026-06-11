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

long long L[100] = {0};

long long luca(long long n){
	if(L[n] > 0){
		return L[n];
	}
	if(n == 0){
		L[0] = 2;
		return 2;
	}
	if(n == 1){
		L[1] = 1;
		return 1;
	}
	long long ret = luca(n-1) + luca(n-2);
	L[n] = ret;
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;

	long long ans = luca(N);
	printf("%lld\n", ans);
	return 0;
}