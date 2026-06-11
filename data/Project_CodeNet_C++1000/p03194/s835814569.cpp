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

vector<ll> v;
bool p[MAXX];
int main()
{
	FAST;
	ll n, k;
	cin >> n >> k;
	if(n == 1){
		cout << k;
		return 0;
	}
	ll h = n -1;
	ll mx = 0;
	for(ll i = 1; i <= 1000000; i++){
		if(k % i == 0){
			ll x = 0;
			ll a = pow(i, h);
			if(k % a == 0){
				mx = max(mx, __gcd(i, k/a));
			}
		}
	}
	cout << mx;
	return 0;
}