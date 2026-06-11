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
	ll n;
	cin >> n ;
	ll a[n+4];
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a, a + n);
	ll x = 0;
	for(ll i = 0; i < n-1; i ++){
		x += a[i];
	}
	x += (a[n-1] / 2);
	cout << x;
	return 0;
}