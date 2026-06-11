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
	long long N;
	long long A[100000+2] = {0};

	cin >> N;

	long long tot = 0;
	for(int i=1; i<=N; i++){
		cin >> A[i];
		tot += abs(A[i] - A[i-1]);
	}
	tot += abs(A[N]);

	for(int i=1; i<=N; i++){
		long long d = 0;
		d -= abs(A[i + 1 ] - A[i]);
		d -= abs(A[i] - A[i - 1]);
		d += abs(A[i + 1] - A[i - 1]);
		printf("%lld\n", tot+d);
	}
	return 0;
}