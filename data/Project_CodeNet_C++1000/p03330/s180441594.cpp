#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, C;  cin >> N >> C;
	vector<vector<int>> D(C, vector<int>(C));
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			cin >> D[i][j];
		}
	}
	/*
	for (int k = 0; k < C; k++) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < C; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	*/
	//vector<vector<int>> c(N, vector<int>(N));
	vector<vector<ll>> cnt(3, vector<ll>(C));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int c; cin >> c;
			cnt[(i + j) % 3][c - 1]++;
		}
	}
	ll ans = 1e15;
	//cost[remaider][color]=cost
	vector<vector<ll>> cost(3, vector<ll>(C));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < C; k++) {
				cost[i][j] += cnt[i][k] * D[k][j];
			}
		}
	}
	
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < C; k++) {
				if (i == j || j == k || k == i) continue;
				ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
				//printf("i=%d j=%d k=%d ans=%lld\n", i, j, k, ans);
			}
		}
	}
	cout << ans << endl;
}

