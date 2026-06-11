#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,m;
	cin >> n >> m;

	ll ans = -1;
	for(ll i = 1; i*i<=m; i++){
		if(m % i != 0) continue;

		ll tmp = m/i;
		if(n * i <= m) ans = max(ans, i);
		if(n * tmp <= m) ans = max(ans, tmp);
	}

	cout << ans << endl;
}