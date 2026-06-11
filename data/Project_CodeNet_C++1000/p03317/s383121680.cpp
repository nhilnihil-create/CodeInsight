#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
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
	ll m;
	cin >> m;
	ll a[n+5];
	ll x = 0;
	ll mn = INT_MAX;
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	ll ans = 0;
	n -= m;
	ans++;
 
	if (n > 0) {
		m --;
		ans += (n + m - 1) / m;
	}
	cout << ans << endl;
	return 0;
}