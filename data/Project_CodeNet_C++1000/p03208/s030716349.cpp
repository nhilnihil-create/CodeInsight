#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long  int 
 
#define mod  1000000007


int main()
{
	FAST;
	ll n; ll k;
	cin >> n >> k;
	ll a[n+5];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	ll x = INT_MAX;
	sort(a, a + n);
	for(ll i = 0; i <= n-k; i ++){
		x = min(x, (a[i+k-1] - a[i]));
	} cout << x;
	return 0;
}