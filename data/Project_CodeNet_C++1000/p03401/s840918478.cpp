#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> d(n+1);
	d[0] = a[0];
	rep(i,n-1) d[i+1] = a[i+1] - a[i];
	d[n] = 0 - a[n-1];
	ll dist_base = 0;
	rep(i,n+1) dist_base += abs(d[i]);
	rep(i,n) cout << dist_base - (abs(d[i]) + abs(d[i+1]) - abs(d[i] + d[i+1])) << endl;

	return 0;
}
