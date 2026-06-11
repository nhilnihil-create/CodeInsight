//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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
#define inf 1e14
#define MOD 1000000007

bool cmp(pll a, pll b)
{

    return a.ss  < b.ss;
}

int main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> vv;
    map<ll,ll> m;
    for(ll i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        if(m[x]==0) vv.pb(x);
        m[x]++;
    }
    vector<pll> v;
    for(ll i = 0;i<vv.size(); i++)
    {

        ll x = vv[i];
        v.pb(mp(x,m[x]));
    }
    ll z;
    if(vv.size() <= k) z=0;
    else z = vv.size()-k;
    sort(all(v),cmp);
    ll ans = 0;
    for(ll i = 0; i  <z; i++) ans+=v[i].ss;
    cout << ans;
}
