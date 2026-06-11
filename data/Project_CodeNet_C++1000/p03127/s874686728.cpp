#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;


ll ans, cnt;

// 最大公約数のll版
ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	return b == 0 ? a : gcd(b, a%b);
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> A(N);
	rep(i, N) {
		ll a;
		cin >> a;
		if (i == 0) ans = a;
		else{
			ans = gcd(ans,a);
		}
	}

	cout << ans << endl;

	return 0;
}
