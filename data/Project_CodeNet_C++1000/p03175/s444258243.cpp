#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
const lli INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1e9 + 7;
const lli MH1 = 1599614977, MH2 = 2034417103, MH3 = 1090250123, MH4 = 2024491871; 
const int N = 1e5 + 10;
vector<int> graph[N];
lli dp[N][2];
lli bpow(lli baseee, lli exponenttt) {
	if(exponenttt < 0) return 0;
	lli res = 1;
	baseee %= MOD;
	while (exponenttt > 0) {
		if ((exponenttt & 1) == 1) res = (res*baseee) % MOD;
		baseee = (baseee*baseee) % MOD;
		exponenttt >>= 1;
	}
	return res;
}
lli multInverse(lli a) {//if_mod_is_prime
	return bpow(a, MOD - 2);
}
lli divm(lli a, lli b) {//if_mod_is_prime
	return (a * multInverse(b)) % MOD;
}
lli multm(lli a, lli b) {
	return (a * b) % MOD;
}
lli subm(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli addm(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
void dfs(int v, int par) {
	dp[v][0] = 1;
	dp[v][1] = 1;
	for(int i : graph[v]) {
		if(i == par) continue;
		dfs(i, v);
		dp[v][0] = multm(dp[v][0], dp[i][1]);
		dp[v][1] = multm(dp[v][1], addm(dp[i][0], dp[i][1]));
	}
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(1, -1);
	cout << addm(dp[1][0], dp[1][1]) << "\n";
	
	return 0;
}