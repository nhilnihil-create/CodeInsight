#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long int
 
#define mod  1000000007
 
 
 
int main()
{
	FAST;
	ll n, m;
	cin >> n >> m; 
	ll ans = 0;
	for(ll i = n; i <= m; i++){
		ll a = i/10000;
		ll b = i/1000    %10;
		ll c = i/10      %10;
		ll d = i%10;
		if(a == d && c == b){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}