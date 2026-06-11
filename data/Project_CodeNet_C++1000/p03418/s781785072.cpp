#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 1～nまでの整数でbで割った余りがk以上となるものの数を算出
ll f(ll b, ll k, ll n) {
	if (k==0) return n;
	ll d = n / b;
	ll r = n % b;
	ll cnt_low = d*k + min(r+1,k) - 1;
	return n - cnt_low;
}

int main() {
	ll n,k;
	cin >> n >> k;
	ll ans = 0;
	for(ll b=k+1;b<=n;b++) {
		ans += f(b,k,n);
	}
	cout << ans << endl;

	return 0;
}
