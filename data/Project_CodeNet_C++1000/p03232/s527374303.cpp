#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MOD = 1000000007;
typedef long long ll;

ll N, arr[MAXN];

ll pkt(ll a, ll b) {
	if (b == 0) return 1;
	else if (b&1) return pkt(a, b-1)*a%MOD;
	else {
		ll tmp = pkt(a, b/2);
		return tmp*tmp%MOD;
	}
}

ll inv(ll x) {
	return pkt(x, MOD-2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	ll fact = 1;
	for (int i = 1; i <= N; i++) fact = fact*i%MOD;
	
	ll cur = 0;
	for (int i = 0; i < N; i++) {
		cur = (cur + inv(i+1))%MOD;
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans = (ans + cur*arr[i])%MOD;
		cur = (cur - inv(N-i) + inv(i+2) + MOD)%MOD;
	}
	ans = ans*fact%MOD;
	cout << ans << "\n";
	
	return 0;
}
