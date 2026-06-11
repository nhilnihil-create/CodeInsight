#include <bits/stdc++.h>
#define INF 999999999999999
using namespace std;

typedef long long ll;

int main(){
	ll n, c;
	cin >> n >> c;
	ll v[n]; ll x[n];
	ll ans = 0;
	ll ri[n+1]; ll rit[n+1];
	ll op[n+1]; ll opt[n+1];
	ri[0]=0; rit[0]=0;
	op[0]=0; opt[0]=0;
	ll risum=0; ll ritsum=0;
	for(ll i = 0; i < n; i++){
		cin >> x[i] >> v[i];
		if(i)risum += v[i]-(x[i]-x[i-1]), ri[i+1] = max(ri[i], risum), ritsum += v[i]-(x[i]-x[i-1])*2, rit[i+1] = max(rit[i], ritsum);
		else risum = ri[i]+v[i]-x[i], ri[i+1] = max(ri[i], risum), ritsum = rit[i]+v[i]-x[i]*2, rit[i+1] = max(rit[i], ritsum);
	}
	ll opsum=0;
	ll optsum=0;
	for(ll i = 0; i < n; i++){
		if(i)opsum += v[n-i-1]-(x[n-i]-x[n-i-1]), op[i+1] = max(op[i], opsum), optsum += v[n-i-1]-(x[n-i]-x[n-i-1])*2, opt[i+1] = max(opt[i], optsum);
		else opsum = op[i]+v[n-i-1]-(c-x[n-i-1]), op[i+1] = max(op[i], opsum), optsum = opt[i]+v[n-i-1]-(c-x[n-i-1])*2, opt[i+1] = max(opt[i], optsum);
	}
	for(ll i = 0; i <= n; i++){
		ans = max(ans, max(ri[i]+opt[n-i], rit[i]+op[n-i]));
	}
	cout << ans << endl;
    return 0;
}