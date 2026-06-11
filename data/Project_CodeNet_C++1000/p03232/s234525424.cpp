
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)

const ll mod = 1e9+7;

ll modpow(ll a, ll b) {
	return b?modpow(a*a%mod,b/2)*(b&1?a:1)%mod:1;
}

void add(ll &a, ll b) {
	if (b>=mod) b%=mod;
	a += b; if (a >= mod) a-=mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	int a[n];
	f(i,0,n) cin >> a[i];
	ll pre[n];
	f(i,0,n) pre[i] = ((i?pre[i-1]:0)+modpow(i+1,mod-2))%mod;
	ll ans = 0;
	f(i,0,n) {
		add(ans,a[i]*pre[i]);			
		add(ans,a[i]*pre[n-1-i]);
		add(ans,mod-a[i]);
	}
	f(i,0,n) ans = (ans*(i+1))%mod;
	cout << ans << endl;
	return 0;
}
	
