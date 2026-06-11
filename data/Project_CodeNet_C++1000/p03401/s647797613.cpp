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

void solve_abc092() {
	ll n;
	ll ans = 0;

	cin >> n;

	V a(n + 2);

	a[0] = 0;
	rep(i, n) {
		cin >> a[i + 1];
	}
	a[n + 1] = 0;

	V s(n + 2);
	s[0] = 0;
	rep(i, n + 1) {
		s[i + 1] = s[i] + abs(a[i + 1] - a[i]);
	}

	rep(i, n) {
		ans = s[n + 1] - abs(a[i + 1] - a[i]) - abs(a[i + 2] - a[i + 1]) + abs(a[i + 2] - a[i]);
		cout << ans << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc092();

	return 0;
}