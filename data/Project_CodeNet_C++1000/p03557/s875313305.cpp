#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
typedef long long ll;

int n;
ll a[110000];
ll b[110000];
ll c[110000];

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	ll ans = 0;
	rep(i, n) {
		ll A = (lower_bound(a, a + n, b[i]) - a);
		ll C = n - (upper_bound(c, c + n, b[i]) - c);
		ans += A * C;
	}
	cout << ans << endl;
	return 0;
}
