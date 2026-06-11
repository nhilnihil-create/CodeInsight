#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 50 + 69;
const int base = 311;

// dung inverse module de tinh nCk
// beginer 74
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

int n, m, k;

bool vs[e], chk;
ll a[55], b[55];

int main()
{
    cin >> n >> k;
    vector<ll>x;
    vector<ll>y;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
        x.pb(a[i]);
        y.pb(b[i]);

    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    //for(auto i : x) cout << i << " ";
    //cout << "\n";
    //for(auto i : y) cout << i << " ";
    //cout <<"\n";
    //cout << x[n-1] - x[0]  << " "<<y[n-1] <<"\n";
    ll ans = 5*1e18;
    ans = min(ans, (x[n-1] - x[0])*(y[n-1] - y[0]));
    for(int i=0; i<n-1; i++)
    {
        for(int i1=i+1; i1<n; i1++)
        {
            for(int j=0; j<n-1; j++)
            {
                for(int j1=j+1; j1<n; j1++)
                {
                    ll mn = x[i];
                    ll mx = x[i1];
                    ll mny = y[j];
                    ll mxy = y[j1];
                    ll dem = 0;
                    for(int z=0; z<n; z++)
                    {
                        if(mn <= a[z] && a[z] <= mx && mny <= b[z] && b[z] <= mxy) dem++;
                    }
                    if(dem >= k) ans = min(ans, 1LL *(mx - mn)*(mxy - mny));
                }
            }
        }
    }
    cout << ans;

}
/*

*/
