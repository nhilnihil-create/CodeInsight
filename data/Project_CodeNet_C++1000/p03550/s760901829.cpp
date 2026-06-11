#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int mod = 1000000007;

int main() {
	ll n, z, w;
	cin >> n >> z >> w;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	if (n == 1) {
		cout << abs(a[0] - w) << endl;
		return 0;
	}
	ll ans = max(abs(a[n - 1] - w), abs(a[n - 1] - a[n - 2]));
	cout << ans << endl;
	return 0;
}
