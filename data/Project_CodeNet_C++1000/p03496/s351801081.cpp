#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 55;
const int base = 311;

// dung inverse module de tinh nCk
// beginer 81
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
ll a[e];

int main()
{
   cin >> n;
   ll maxx ;
   ll minn = 1e18;
   ll posmn, posmx;
   for(int i=1; i<=n; i++)
   {
       cin >> a[i];
       if(i == 1)
       {
           maxx = a[i];
           posmx = 1;
           continue;
       }
       if(abs(a[i]) > abs(maxx))
       {
           maxx = a[i];
           posmx = i;
       }
   }
   cout << 2*n - 1 <<"\n";
   for(int i=1; i<=n; i++)
   {
       cout << posmx <<" "<<i<<"\n";
   }
   if(maxx > 0)
   {
       for(int i=2; i<=n; i++)
       {
           cout << i-1 <<" "<<i<<"\n";
       }
   }
   else
   {
       for(int i=n; i>=2; i--)
       {
           cout << i<<" "<<i-1<<"\n";
       }
   }
}
/*

*/
