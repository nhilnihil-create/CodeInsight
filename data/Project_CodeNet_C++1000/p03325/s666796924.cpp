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
	ll a, b;
	ll n;
	cin >> n;
	ll x = 0;
	for(ll i = 0; i < n; i ++){
		cin >> a;
		while(a % 2 ==0){
			x ++;
			a /= 2;
		}
	}
	cout << x;
	return 0;
}