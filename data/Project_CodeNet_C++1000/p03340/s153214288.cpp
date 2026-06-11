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

ll bit = 21;
V sum[21];

void solve_abc_d() {
	ll n, m, x, k;
	ll ans = 0;
	cin >> n;

	V a(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, bit) {
		sum[j] = V(n + 1, 0);
	}

	ll d;
	rep(i, n) {
		rep(j, bit) {
			d = (a[i] >> j) & 1;
			sum[j][i + 1] = sum[j][i] + d;
		}
	}

	ll len;
	ll tmp;
	V now;
	rep(i, n) {
		len = INF;
		rep(j, bit) {
			d = (a[i] >> j) & 1;
			tmp = sum[j][i];
			auto itr = upper_bound(ALL(sum[j]), tmp + 1);
			if (itr != sum[j].end()) {
				tmp = itr - sum[j].begin();
				len = min(len, tmp - i - 1);
			}
			else {
				len = min(len, n - i);
			}

		}
		ans += len;
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
