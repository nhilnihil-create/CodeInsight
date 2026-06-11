#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 100100100;
const ll llINF = 1LL << 60;
ll chmin(ll a, ll b)
{
	return a > b ? b : a;
}
int main()
{
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	vector<ll> v(n);
	rep(i, n) {
		cin >> v[i];
		ans += v[i];
	}
	sort(v.begin(), v.end());
	vector<pair<ll, ll>> change(m);
	rep(i, m) cin >> change[i].second >> change[i].first;	// cでソートしたいので, cをfirstに入れる
	sort(change.rbegin(), change.rend());
	vector<ll> comp;
	int c = 0;
	rep(i, m) {
		rep(j, change[i].second) {
			comp.push_back(change[i].first);
			c++;
			if (c == n)	break;
		}
		if (c == n)	break;
	}
	int s = comp.size();
	rep(i, s) {
		if (v[i] < comp[i])	ans += comp[i] - v[i];
		else break;
	}
	cout << ans << endl;
	return 0;
}
