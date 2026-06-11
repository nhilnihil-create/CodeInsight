#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll t[100001];
ll ch[100001];

void solve_abc_d() {
    ll n, c;
	ll ans = 0;

	cin >> n >> c;
	vector<P> s;
	ll p, q, r;
	rep(i, n) {
		cin >> p >> q >> r;
		s.push_back(make_pair(p, i));
		t[i] = q;
		ch[i] = r;
	}

	sort(ALL(s));

	ll idx, st, et, ec, nt, nc;
	priority_queue<P> pq;
	priority_queue<P> tmp;

	rep(i, n) {
		idx = s[i].second;
		st = s[i].first;
		et = t[idx];
		ec = ch[idx];

		if (pq.size() == 0) {
			pq.push(make_pair(-et, ec));
		}
		else {
			nt = -pq.top().first;
			nc = pq.top().second;
			if (nt < st) {
				pq.pop();
			}
			else if (st == nt) {
				if (ec == nc) {
					pq.pop();
				}
				else {
					while (st == -pq.top().first) {
						tmp.push(make_pair(pq.top().first, pq.top().second));
						pq.pop();
						if (pq.size() == 0) {
							break;
						}
						else  if (st == -pq.top().first) {
							if (ec == pq.top().second) {
								pq.pop();
								break;
							}
						}
					}
					while (tmp.size()>0) {
						pq.push(make_pair(tmp.top().first, tmp.top().second));
						tmp.pop();
					}
				}
			}

			pq.push(make_pair(-et, ec));
		}
	}

	ans = pq.size();

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_d();

	return 0;
}
