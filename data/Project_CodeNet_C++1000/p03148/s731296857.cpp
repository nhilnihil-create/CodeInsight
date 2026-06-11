#include<bits/stdc++.h>
using namespace std;
 
#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e9
#define MOD 1000000007
 
bool cmp(pll a, pll b)
{
 
    return a.ff > b.ff;
}
 
int main()
{
 
    ll n, k;
    cin >> n >> k;
    ll tmp = 0;
    vector<pll> v;
    for(ll i = 0; i < n; i++)
    {
 
        ll x, y;
        cin >> x >> y;
        v.pb(mp(y, x));
    }
    sort(all(v), cmp);
    map< ll, ll > m;
    ll tp  =0;
    for(ll i = 0; i < k; i++)
    {
 
        tmp+=v[i].ff;
        if(m[v[i].ss] == 0) tp++;
        m[v[i].ss]++;
    }
    //cout << "ANS " << tmp << endl;
    ll ans = tmp + tp*tp;
    //cout << ans << endl;
    ll l = k-1, r = k;
    while(1)
    {
 
        if(l < 0 || r >= n) break;
        while(l >= 0 && m[v[l].ss]==1) l--;
        if(l < 0) break;
        m[v[l].ss]--;
        tmp-=v[l].ff;
 
        while(r < n && m[v[r].ss]>0) r++;
        if(r >= n) break;
        m[v[r].ss]++;
        tmp+=v[r].ff;
        tp++;
 
        ll xx = tmp+tp*tp;
 
        ans = max(ans, xx);
      l--;
      r++;
    }
    cout << ans;
}