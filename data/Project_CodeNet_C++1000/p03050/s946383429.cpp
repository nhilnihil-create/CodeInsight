#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll ans = 0;
	for(ll i=1; i*i<=n; ++i){
		if(n%i==0){
			ll m=n/i-1;
			if(m>i) ans += m;
		}
	}
	cout << ans <<"\n";
}