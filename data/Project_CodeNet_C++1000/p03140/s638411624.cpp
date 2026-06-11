#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_zenkoku1_b() {
	ll N;
	string A, B, C;

	cin >> N >> A >> B >> C;

	ll ans = 0;
	ll cnt = 0;
	rep(i, N) {
		cnt = 0;
		if (A[i] == B[i]) {
			cnt++;
		}
		if (B[i] == C[i]) {
			cnt++;
		}
		if (C[i] == A[i]) {
			cnt++;
		}

		if (cnt == 0) ans += 2;
		else if (cnt == 1) ans += 1;
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_zenkoku1_b();

	return 0;
}