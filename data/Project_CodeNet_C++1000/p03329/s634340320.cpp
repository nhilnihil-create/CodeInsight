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

#define MAX 100000

int dp[MAX+2] = {0};
int done[MAX+2] = {0};

void f(int n){
	//n回で支払える金額をdpに埋める。
	if(done[n] == 1) return;

	if(n == 1){
		dp[1] = 1;
		int u = 1;
		for(u = 1; u <= MAX; ){
			u = u*6;
			if(u <= MAX){ dp[u] = 1; }
		}
		for(u = 1; u <= MAX; ){
			u = u*9;
			if(u <= MAX){ dp[u] = 1; }
		}
	}
	else if(n > 1){
		f(n - 1);
		for(int i = 1; i <= MAX; i++){
			if(dp[i] == n -1){
				if(dp[i+1] == 0){ dp[i+1] = n; }
				int u;
				for(u = 1; i + u <= MAX;){
					u = u*6;
					if(i + u <=MAX && dp[i + u] == 0){ dp[i + u] = n; }
				}
				for(u = 1; i + u <= MAX;){
					u = u*9;
					if(i + u <= MAX && dp[i + u] == 0){ dp[i + u] = n; }
				}
			}
		}
	}
	done[n] = 1;
}

int main(int argc, char* argv[]){
	int N;
	cin >> N;

	for(int i=1; ; i++){
		f(i);
		if(dp[N] != 0) break;
	}
	cout << dp[N] << endl;
	return 0;
}