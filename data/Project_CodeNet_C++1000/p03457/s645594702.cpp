#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007




int main()
{
	FAST;
	ll n;
	cin >> n;
	ll x[n+6], y[n+7];
	ll t[n+6];
	ll h1 = 0;
	ll op = 0;
	bool ans = true;
	for(ll i = 0; i < n; i++){
		cin >> t[i] >> x[i] >> y[i];
		ll h = abs(x[i] + y[i] - op);;
		ll t1 = t[i] - h1;
		if((t1 - h) % 2 != 0 || (t1 - h) < 0){
			ans = false;
		}
		h1 = t[i];
		op = x[i] + y[i];
	}
	if(ans){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}