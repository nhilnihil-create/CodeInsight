#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 int
 
#define mod  1000000007

map<string, int> m;

int main()
{
	FAST;
	ll n;
	cin >> n;
	ll x;
	cin >> x;
	
	ll a[n+4]; ll b[n+6];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		b[i] = abs(x - a[i]);
	}
	sort(b, b + n);
	ll m = b[0];
	for(ll i = 1; i < n; i++){
		m = __gcd(m, b[i]);
	}
	cout << m;
	return 0;
}