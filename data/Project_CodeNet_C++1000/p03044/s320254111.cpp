#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}
int n;
typedef pair<int, int>p;
vector<vector<p>>G;
vector<int>dist;
queue<int>que;

void dfs(int v) {
	dist[v] = 0;
	que.push(v);
	while (!que.empty()) {
		int next = que.front();
		que.pop();
		int d = dist[next];
		rep(i, G[next].size()) {
			int pi = G[next][i].first;
			int di = G[next][i].second;
			if (dist[pi] != -1)continue;
			dist[pi] = (d + di)%2;
			que.push(pi);
		}
	}
}


signed main(void) {
	cin >> n;
	G.resize(n);
	dist.resize(n);
	rep(i, n) {
		dist[i] = -1;
	}
	rep(i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		w = w % 2;
		G[u].pb(make_pair(v, w));
		G[v].pb(make_pair(u, w));
	}
	dfs(0);
	rep(i, n) {
		println(dist[i]);
	}
}