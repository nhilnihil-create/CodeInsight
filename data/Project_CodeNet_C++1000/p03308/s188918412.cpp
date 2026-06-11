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
	ll a[n+3];
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
		
	}
	sort(a, a + n);
	cout << a[n-1] - a[0];
	return 0;
}