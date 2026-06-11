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
vl flag, color; vll path; vl D; ll C;
//***********//
void bfs(ll now) {
	queue<ll> Q;
	Q.push(now);
	D[now] = 0;
	flag[now] = 1;
	ll u;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (ll v = 0; v < path[u].size(); v++) {
			ll next = path[u][v];
			if (flag[next] == 0) {
				D[next] = D[u] + 1;
				if (D[next] % 2 == 0) flag[next] = 1;
				else flag[next] = 2;
				Q.push(next);
			}
		}
	}
}
int main() {
	cin >> N >> M;
	flag.resize(N);
	path.resize(N);
	D.resize(N);
	vpll P(M);
	for (i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		P[i] = make_pair(a, b);
		path[a].push_back(b);

		path[b].push_back(a);
	}
	bfs(0);
	ll isBG = 1;
	for (i = 0; i < M; i++) {
		//cout << P[i].first << P[i].second << endl;
		if (flag[P[i].first] == flag[P[i].second]) {
			isBG = 0;
			break;
		}
	}
	if (isBG) {
		ll B = 0, W = 0;
		for (i = 0; i < N; i++) {
			if (flag[i] == 1) B++;
			else W++;
		}
		//cout << "a";
		cout << B * W - M;
	}
	else {
		cout << N * (N - 1) / 2 - M;
	}
}