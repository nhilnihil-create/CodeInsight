#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 1e6 + 69;
const int base = 311;

// dung inverse module de tinh nCk
// beginer 82
// mbeginer 162
// cach tao hoan vi tu n so : n*(n+1)/2;

//vector<pair<ll,ll>>adj[e];
//vector<ll>adj[e];

/*ll Pow(ll n, ll dem)
{
    if(dem == 0) return 1;
    if(dem == 1) return n ;
    ll t = Pow(n, dem/2);
    if(dem % 2 == 0) return (t*t);
    else return ((t * t) * n);
}*/

/*ll C(ll k, ll n)
{
    if(k == 0) return 1;
    if(n < k) return 0;
    return (gt[n]%mod * (igt[k]%mod * igt[n-k]%mod)%mod)%mod;
}*/


int main()
{
    ll x, y;
    cin >> x >> y;
    ll k =y/x;
    ll dem = 0;
    while(k > 0)
    {
        k /= 2;
        dem ++;
    }
    cout << dem ;
}
/*

*/
