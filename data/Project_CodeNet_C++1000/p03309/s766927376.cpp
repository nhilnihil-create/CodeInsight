#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 10000000000000;
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

// ll modexp(ll x, ll y, ll p)
// {
// 	ll res = 1;
// 	x = x % p;
// 	while (y > 0)
// 	{
// 		if (y & 1)
// 			res = (res * x) % p;
// 		y = y >> 1;
// 		x = (x * x) % p;
// 	}
// 	return res;
// }

// ll mulmod(ll a, ll b)
// {
// 	return ((a % mod) * (b % mod)) % mod;
// }

// ll sub_mod(ll a, ll b, ll m){
//    if (a >= b)
//        return a - b;
//    else
//        return m - b + a;
// }

// ll add_mod(ll a, ll b){
//    if (0 == b) 
//        return a;

//    b = mod - b;
//    if (a >= b)
//        return a - b;
//    else
//        return mod - b + a;
// }

// ll gcd(ll a, ll b)
// {
// 	if (a == 0)
// 		return b;
// 	else
// 		return gcd(b % a, a);
// }

// ll modInv(ll a) 
// { 
//     ll g = gcd(a, mod); 
//     if (g != 1) 
//         return -1; 
//     else
//         return modexp(a, mod-2, mod); 
// } 


int main()
{
	fastio;
//#ifndef ONLINE_JUDGE   
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	ll n = 0;
	cin >> n;
	vector<ll>v(n+1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] -= i;
	}
	sort(v.begin()+1, v.end());
	ll m = 0;
	if (n & 1)
		m = v[(n+1)/2];
	else
		m = (v[n/2]+v[n/2+1])/2;
	ll s = 0;
	for (ll i = 1; i <= n; ++i)
	{
		s += (abs(v[i] - m));
	}
	cout << s;
}

