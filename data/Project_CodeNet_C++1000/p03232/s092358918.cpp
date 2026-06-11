#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, a, ans, M=1e9+7, s[100005]={0,1};

ll pow(ll p, ll q) {
	ll re=1;
	for(; q; q>>=1) {
		if(q&1) re = re * p % M;
		p = p * p % M;
	}
	return re;
}

int main() {
	ll i;
	cin >> n;
	for(i=2; i<=n; i++) s[i] = (s[i-1] + pow(i, M-2)) % M;
	for(i=1; i<=n; i++) {
		scanf("%lld", &a);
		ans += a * ((s[i] + s[n-i+1] - 1 + M) % M) % M;
	}
	for(i=1; i<=n; i++) (ans *= i) %= M;
	cout << ans;
	return 0;
}