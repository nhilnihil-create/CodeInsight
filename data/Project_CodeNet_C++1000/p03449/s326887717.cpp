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

	long long N;
	int A[4][100+2] = {0};

	cin >> N;
	for(int i=1; i<=2; i++){
		for(int j=1; j<=N; j++){
			cin >> A[i][j];
		}
	}

	long long ans = 0;
	for(int i=1; i<=N; i++){
		long long c = 0;
		//マス(i, N)で下に折れる
		for(int j=1; j<=i; j++){
			c += A[1][j];
		}
		for(int j=i; j<=N; j++){
			c += A[2][j];
		}
		if(ans < c){
			ans = c;
		}
	}
	printf("%lld\n", ans);
	return 0;
}