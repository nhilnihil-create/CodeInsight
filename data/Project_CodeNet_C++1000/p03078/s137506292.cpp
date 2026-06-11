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
#define LLINF 1e18

void solve_abc_d() {
	ll n, m;
	//ll a, b;
	ll x, y, z;
	ll h, w;
	ll k;
	ll l_ans = 0;

	cin >> x >> y >> z >> k;

	V a, b, c;
	ll tmp;
	rep(i, x) {
		cin >> tmp;
		a.push_back(tmp);
	}
	rep(i, y) {
		cin >> tmp;
		b.push_back(tmp);
	}
	rep(i, z) {
		cin >> tmp;
		c.push_back(tmp);
	}

	V ab;
	rep(i, x) rep(j, y) {
		ab.push_back(a[i] + b[j]);
	}

	sort(RALL(ab));

	priority_queue<ll> ans;
	rep(i, min(x*y, k)) {
		rep(j, z) {
			ans.push(ab[i] + c[j]);
		}
	}

	rep(i, k) {
		cout << ans.top() << "\n";
		ans.pop();
	}

	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
