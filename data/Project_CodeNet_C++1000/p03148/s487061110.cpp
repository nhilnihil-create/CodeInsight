#include <bits/stdc++.h>
#include <unordered_set>

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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_d() {
	ll n, k;
	ll ans = 0;
	cin >> n >> k;

	vector<P> td(n);

	ll t, d;
	rep(i, n) {
		cin >> t >> d;
		td[i] = make_pair(d, t);
	}

	sort(RALL(td));

	ll sumD = 0;
	ll sumT = 0;
	V used(n + 1, 0);
	priority_queue<P> pq;
	vector<V> neta(n + 1);
	rep(i, k) {
		d = td[i].first;
		t = td[i].second;
		sumD += d;
		used[t]++;
		if (used[t] == 1) {
			sumT++;
		}
		neta[t].push_back(d);
		pq.push(make_pair(-d, t));
	}

	ans = sumD + sumT * sumT;

	P c;
	rep2(i, k, n) {
		d = td[i].first;
		t = td[i].second;

		if (used[t] == 0) {
			while (pq.size()>0) {
				c = pq.top();
				if (neta[c.second].size() > 1) {
					sumD += d + c.first;
					pq.pop();
					sumT++;
					used[t]++;
					ans = max(ans, sumD + sumT * sumT);
					break;
				}
				pq.pop();
			}
		}
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_d();

	return 0;
}
