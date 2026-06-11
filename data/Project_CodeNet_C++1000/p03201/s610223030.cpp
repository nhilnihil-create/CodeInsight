#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <utility>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef pair<ll, double> PD;
ll mod = 1000000007;
//ll mod = 998244353;

ll powtwo(ll n) {
	ll cnt = 0;
	while (n > 0) {
		n /= 2;
		cnt++;
	}
	return (1 << cnt);
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp.insert(P(a[i], 0));
		mp[a[i]]++;
	}
	sort(all(a));
	a.push_back(LINF);
	ll ans = 0;
	vector<bool> flag(n, true);
	for (int i = n - 1; i >= 0; i--) {
		if (!flag[i]) continue;
		mp[a[i]]--;
		ll find = powtwo(a[i]) - a[i];
		ll pl = lower_bound(all(a), find) - a.begin();
		if (!mp[find]) continue;
		pl += mp[find] - 1;
		if (flag[pl]) {
			flag[pl] = false;
			flag[i] = false;
			mp[find]--;
			ans++;
		}
	}
	cout << ans << endl;
}