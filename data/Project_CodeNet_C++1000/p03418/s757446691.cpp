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

void solve_abc090() {
	ll n, k;
	ll ans = 0;

	cin >> n >> k;

	ll a, b;
	ll diff;
	rep2(b, k + 1, n + 1) {
		// a < b: a = k ~ b - 1
		ans += max(b - k, 0LL) * (n/b);

		ans += max((n % b) - max(k, 1LL) + 1, 0LL);
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc090();

	return 0;
}