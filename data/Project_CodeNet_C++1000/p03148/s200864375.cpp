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
	return firstElof.second > secondElof.second;
}
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, bitList, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D;
//***********//
int main() {
	cin >> N >> K;
	vpll F(N);
	for (i = 0; i < N; i++) {
		cin >> F[i].first >> F[i].second;
	}
	sort(F.begin(), F.end(),pairCompare);
	priority_queue<pll> Q;
	vl C(N);
	for (i = 0; i < N; i++) {
		C[i] = 0;
	}
	ll P = 0;
	for (i = 0; i < K; i++) {
		Q.push(make_pair(F[i].second*(-1), F[i].first-1));
		P += F[i].second;
		C[F[i].first - 1]++;
	}
	ll V = 0;
	for (i = 0; i < N; i++) {
		if (C[i] > 0) V++;
	}
	ans = P + V * V;
	ll nowF = K;
	for (i = 0; i < K; i++) {
		//cout << Q.top().first << " " << Q.top().second << endl;
		if (C[Q.top().second] >= 2) {
			while (nowF < N && C[F[nowF].first-1] != 0) nowF++;
			if (nowF == N)break;
			C[Q.top().second]--;
			C[F[nowF].first - 1]++;
			P -= Q.top().first * (-1);
			P += F[nowF].second;
			V++;
			ans = max(ans, P + V * V);
			nowF++;
		}
		//cout << P + V * V << endl;
		Q.pop();
	}
	cout << ans;
}
	
