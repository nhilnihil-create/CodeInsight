#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

ll ss[MAXX];

int main()
{
	FAST;
	ll n;
	cin >> n;
	ll ans = 0;
	for(ll i = 105; i <= n; i+= 2){
		ll x = 0;
		for(ll j = 1; j * j < i; j++){
			if(i % j == 0){
				x += 2;
			}
		}
		if(floor(sqrt(i)) == ceil(sqrt(i))){
			x ++;
		}
		if(x == 8 && i % 2){
			ans ++;
		}
}
	cout << ans;
	return 0;
}