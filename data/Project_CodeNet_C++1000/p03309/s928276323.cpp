#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
ll gcd(ll a , ll b){
	if(b == 0) return a;
	return gcd(b , a % b);	
}
ll lcm(ll a , ll b){
	ll g = gcd(a , b);
	ll lc = (a/g) * b;
	return lc;
}
int main()
{
	dhoom;
	int n;
	cin >> n;
	ll a[n];
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		a[i] -= (i+1);
	}
	sort(a , a + n);
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		ans += abs(a[n/2] - a[i]);
	}
	cout << ans << endl;
	return 0;
} 

