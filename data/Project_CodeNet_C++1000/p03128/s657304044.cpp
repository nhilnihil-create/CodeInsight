#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, bitList, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D;
//***********//
int main() {
	cin >> N >> M;
	vl A = {0,0,0,0,0,0,0,0,0};
	for (i = 0; i < M; i++) {
		ll a;
		cin >> a;
		a--; A[a] = 1;
	}
	vl dp(N + 1);
	for (i = 0; i <= N; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	vl cost = { 2,5,5,4,5,6,3,7,6 };
	for (i = 0; i < N; i++) {
		if (i != 0 && dp[i] == -1)continue;
		for (j = 0; j < 9; j++) {
			if (A[j] && i+cost[j]<=N) {
				if (dp[i] + 1 > dp[i + cost[j]]) {
					dp[i + cost[j]] = dp[i] + 1;
						//cout << i + cost[j] << " " << dp[i + cost[j]] << endl;
				}
			}
		}
	}
	ll use = 8;
	string S = "";
	while (N > 0 && use>=0) {
		while (!A[use])use--;
		if (use < 0)break;
		if (N - cost[use] < 0) {
			use--;
		}
		else if (dp[N - cost[use]] == dp[N] - 1) {
			char p = '1' + use;
			S += p;
			N -= cost[use];
		}
		else {
			use--;
		}
	}
	cout << S;
}
	
