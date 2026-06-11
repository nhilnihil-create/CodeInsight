#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll ans = linf;
	for (int i = 0; i <= n - k; ++i) {
		if (a[i + k - 1] <= 0) {
			ll tmp = 0 - a[i];
			mins(ans, tmp);
		}
		else if (a[i] >= 0) {
			ll tmp = a[i + k - 1] - 0;
			mins(ans, tmp);
		}
		else {
			ll tmp = a[i + k - 1] - a[i] + min(a[i + k - 1] - 0, 0 - a[i]);
			mins(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}
