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

void solve_abc_c() {
	ll n;
	ll ans = 0;

	cin >> n;

	V c(n,0), s(n,0), f(n,0);
	rep(i, n - 1) {
		cin >> c[i] >> s[i] >> f[i];
	}

	ll t;
	rep(i, n) {
		t = 0;
		rep2(j, i, n - 1) {
			if (t < s[j]) {
				t = s[j];
			}
			else if (t % f[j] == 0) {
				;
			}
			else {
				t = t + f[j] - t % f[j];
			}
			t += c[j];
		}
		cout << t << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_c();

	return 0;
}