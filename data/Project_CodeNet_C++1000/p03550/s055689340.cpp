#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 2*1e5 + 69;
const int base = 311;

// dung inverse module de tinh nCk
// beginer 78
// mbeginer
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

ll n, m, k;
ll h[e];

int main()
{
    ll maxx = 0;
    ll minn = 1e18;
    cin >> n >> m >> k;
    ll pos = 1e18, pos1 = 1e18;
    for(int i=1; i<=n; i++) cin >> h[i];
    if(n == 1)
        cout << abs(h[1]  - k);
    else cout << max(abs(h[n] - k), abs(h[n-1] - h[n]));
}
/*

*/
