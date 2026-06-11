#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007

vector<ll> v[MAXX];

int main()
{
	FAST;
	ll n, h, w;
	cin >> n >> h >> w;
	ll x = 0;
	
	for(ll i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		if(h <= a && w <= b) x++;
	}
	cout << x;
	return 0;
}