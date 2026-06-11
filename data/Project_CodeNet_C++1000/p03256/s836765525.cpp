#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> G[200000];
bool del[200000];
int main() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	rep(i, m) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fill(del, del + n, false);
	queue<int> q;
	rep(i, n) {
		bool a = false, b = false;
		int len = G[i].size();
		rep(j, len) {
			int v = G[i][j];
			if (s[v] == 'A')a = true;
			if (s[v] == 'B')b = true;
		}
		if (!a || !b) {
			q.push(i); del[i] = true;
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int len = G[x].size();
		rep(j, len) {
			int v = G[x][j];
			if (del[v])continue;
			int k = G[v].size();
			bool a = false, b = false;
			rep(l, k) {
				int vv = G[v][l];
				if (del[vv])continue;
				if (s[vv] == 'A') {
					a = true;
				}
				else b = true;
			}
			if (!a || !b) {
				del[v] = true; q.push(v);
			}
		}
	}
	bool out = false;
	rep(i, n) {
		if (del[i])continue;
		bool a = false, b = false;
		q.push(i); del[i] = true;
		while (!q.empty()) {
			int x = q.front(); q.pop();
				if (s[x] == 'A')a = true;
				else b = true;
			int len = G[x].size();
			rep(j, len) {
				int v = G[x][j];
				if (del[v])continue;
				del[v] = true; q.push(v);
			}
		}
		if (a&&b)out = true;
	}
	if (out)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}