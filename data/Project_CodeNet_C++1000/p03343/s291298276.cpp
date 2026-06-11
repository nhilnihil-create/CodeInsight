#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>


ll n, m, q, ans = INF;
vector<ll> s, list;
int main() {
	cin >> n >> m >> q;
	REP(i, n) {
		ll a;
		cin >> a;
		s.push_back(a);
		list.push_back(a);
	}
	s.push_back(MINF);
	REP(i, n) {
		ll lev = list[i], st = -1, now = 0;
		vector<ll> v;
		REP(j, n + 1) {
			if (s[j] >= lev) {
				if (st == -1) st = j;
				now++;
			}
			else {
				if (now >= m) {
					vector<ll> ss;
					FOR(k, st, j) ss.push_back(s[k]);
					sort(ALL(ss));
					REP(k, now - m + 1)v.push_back(ss[k]);
				}
				now = 0;
				st = -1;
			}
		}
		sort(ALL(v));
		if (v.size() >= q) ans = min(ans, v[q - 1] - lev);
	}
	cout << ans << endl;
}