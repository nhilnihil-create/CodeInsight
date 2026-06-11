#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;
///////////////////////////////////////


ll N, M;
Graph G;
ll w = 0;
ll b = 0;
ll color[100010];
bool dfs(int v,int p) {
	color[v] = p;
	for (int i : G[v]) {
		if (color[i] == p)return false;
		if (color[i] == 0 && !dfs(i, -p))return false;
	}
	return true;
}
int main() {
	cin >> N >> M;
	G.resize(N);
	REP(i, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	REP(i, 100010) {
		color[i] = 0;
	}
	if (dfs(0,1)) {
		REP(i, N) {
			if (color[i] == 1)w++;
			else b++;
		}
		cout << w * b - M << endl;
	}
	else {
		cout << N * (N - 1) / 2 - M << endl;
	}
	return 0;
}