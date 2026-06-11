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
map< string , int > mp;
int main()
{
	dhoom;
	ll n , k;
	cin >> n >> k;
	if(k & 1)
		cout << (n/k)*(n/k)*(n/k) << endl;
	else
		cout << (n/k)*(n/k)*(n/k) + ((n+(k/2))/k)*((n+(k/2))/k)*((n+(k/2))/k) << endl;
	return 0;
} 

