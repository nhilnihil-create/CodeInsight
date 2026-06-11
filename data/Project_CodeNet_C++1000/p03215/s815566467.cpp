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
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, modinv, bitSearch, bitList, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D; ll C;
//***********//
vl bitList(ll n, ll k, ll f) {
	vl bitList(k);
	for (ll i = 0; i < k; i++) {
		bitList[i] = f % n;
		f /= n;
	}
	return bitList;
}
int main() {
	cin >> N >> K;
	vl A(N);
	vl sum(N + 1);
	sum[0] = 0;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
	}
	vl P;
	for (i = 0; i < N; i++) {
		for (j = i+1; j <= N; j++) {
			P.push_back(sum[j] - sum[i]);
		}
	}
	ll L = P.size();
	for (k = 40; k >= 1; k--) {
		ll pre = pow(2, k - 1);
		ll C = 0;
		for (i = 0; i < L; i++) {
			ll Q = (ans + pre) & P[i];
			if (Q == ans + pre) C++;
		}
		if (C >= K) ans += pre;
	}
	cout << ans;
}