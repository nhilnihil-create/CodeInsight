#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	ll sumb = 0, suma = 0;
	rep(i, n) suma += a[i];
	rep(i, n) sumb += b[i];
	ll sum = sumb - suma;
	if (sum < 0) {
		dunk("No");
		return 0;
	}
	ll ca = 0, cb = 0;
	rep(i, n) {
		ll d = a[i] - b[i];
		if (d < 0) {
			d = -d;
			ca += (d + 1) / 2;
			cb += d % 2;
		}
		else {
			cb += d;
		}
	}
	if (sum < ca || sum < cb) {
		dunk("No");
		return 0;
	}
	dunk("Yes");
	return 0;
}
