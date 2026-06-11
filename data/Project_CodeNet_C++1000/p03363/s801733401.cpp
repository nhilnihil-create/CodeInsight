#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll a[int(2*1e5)+100]; 
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	
	map<ll,ll> d;
	d[0] = 1;

	ll sum = 0;
	set<ll> s;
	s.insert(0);
	rep(i,n) {
		sum += a[i];
		s.insert(sum);
		d[sum]++;
	}

	ll ans = 0;
	for (auto itr = s.begin(); itr != s.end(); itr++) {
		ll i = *itr;
		ans += d[i] * (d[i]-1) / 2;
	}
	cout << ans << endl;
	return 0;
}