#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
constexpr int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vvi g(n);
	REP(i, n - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vi d(n, INF);
	{
		d[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			REP(i, g[p].size()) {
				if (d[g[p][i]] == INF) {
					d[g[p][i]] = d[p] + 1;
					q.push(g[p][i]);
				}
			}
		}
	}
	int t = max_element(ALL(d)) - d.begin();
	d = vi(n, INF);
	{
		d[t] = 0;
		queue<int> q;
		q.push(t);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			REP(i, g[p].size()) {
				if (d[g[p][i]] == INF) {
					d[g[p][i]] = d[p] + 1;
					q.push(g[p][i]);
				}
			}
		}
	}
	int s = *max_element(ALL(d));
	if (s % 3 == 1)cout << "Second" << endl;
	else cout << "First" << endl;
}