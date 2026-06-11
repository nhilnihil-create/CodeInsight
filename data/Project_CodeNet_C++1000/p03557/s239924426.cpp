//q020.cpp
//Sat Sep 26 10:51:59 2020

#include <bits/stdc++.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n;
	cin >> n;

	vector<ll> a(n),b(n),c(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	rep(i,n) cin >> c[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	ll ans = 0;
	rep(i,n){
		ll x = b[i];
		ll up = lower_bound(a.begin(),a.end(),x)-a.begin();
		ll down = c.end()-upper_bound(c.begin(),c.end(),x);
		ans += up*down;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}