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
	ll n, m;
	ll ans = 0;

	cin >> n >> m;

	// 隣接数が奇数であれば表、偶数であれば裏
	if (n == 1) {
		if (m == 1) {
			ans = 1;
		}
		else {
			ans = m - 2;
		}
	}
	else if (m == 1) {
		if (n == 1) {
			ans = 1;
		}
		else {
			ans = n - 2;
		}
	}
	else {
		ans = (n - 2) * (m - 2);
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc090();

	return 0;
}