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
ll i, j, k, l, m, n; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D;
//***********//
int main() {
	cin >> N >> M;
	vl A(N);
	vl B(N);
	for (i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) B[0] = A[0] % M;
		else B[i] = (B[i - 1] + A[i]) % M;
	}
	sort(B.begin(), B.end());
	ll now = B[0];
	ll C = 1;
	for (i = 0; i < N; i++) {
		if (i == N-1) {
			ans += C*(C - 1) / 2;
			if (now == 0) ans += C;
		}
		else if (B[i + 1]==now) {
			C++;
		}
		else {
			ans += C * (C - 1) / 2;
			if (now == 0) ans += C;
			C = 1;
			now = B[i + 1];
		}
	}
	cout << ans;
}