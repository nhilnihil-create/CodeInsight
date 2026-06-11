#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll abs64(ll x) {
	if (x>=0) return x;
	else return -x;
}

ll f(vector<ll> a, ll b, ll n) {
	ll ans = 0;
	rep(i,n) ans += abs64(a[i] - b);
	return ans;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
		a[i] -= i+1;
	}
	sort(a.begin(), a.end());
	cout << f(a,a[n/2],n) << endl;
	return 0;
}
