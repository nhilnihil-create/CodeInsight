#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	ll a;
	vector<ll> s(n + 1);
	map<ll, ll> cnt;

	ll ans = 0;
	rep(i, 0, n) {
		cin >> a;
		s[i + 1] = s[i] + a;
		ans += cnt[s[i]]++;
	}
	ans += cnt[s[n]];
	cout << ans;
	return 0;

}
