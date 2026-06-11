#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	ll k;
	cin >> k; 
	vector< pair<ll, ll> > v;
	for(ll i = 0; i < k; i++){
		ll a, b;
		cin >> a >> b;
		v.push_back({b, a});
		
	}
	sort(v.begin(), v.end());
	ll x = 0;
	ll ans = 0;
	for(ll i = 0; i < v.size(); i ++){
		if(x <= v[i].S){
			ans ++;
			x = v[i].F;
		}
	}
	cout << ans;
	return 0;
}