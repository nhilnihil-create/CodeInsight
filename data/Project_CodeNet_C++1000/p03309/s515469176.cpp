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
	ll a[n + 3]; ll m = 0;
	ll f = INT_MAX;
	ll b[n + 6];
	for(ll i = 1; i <= n; i ++){
		cin >> a[i];
		a[i] -= (i+1);
	}
	sort(a + 1, a  + n + 1);
	for(ll i = 1; i<= n; i++){
		m += abs(a[i] - a[n/2 + 1] );
	}
	cout << m;
	return 0;
}