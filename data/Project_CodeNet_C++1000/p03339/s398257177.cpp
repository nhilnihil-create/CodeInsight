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

int main()
{

    ll n;
    string ss;
    cin >> n >> ss;
    vector<ll> lf(n+3, 0), rt(n+3, 0), vl(n+3, 0), vr(n+3, 0);
    for(ll i = 0; i < ss.size(); i++)
    {

        ll idx = i+1;
        if(ss[i] == 'W') vl[idx] = 1;
        else vr[idx] = 1;
    }
    for(ll i = 1; i <= n; i++) lf[i] = lf[i-1]+vl[i];
    for(ll i = 1; i <= n; i++) rt[i] = rt[i-1]+vr[i];
    ll ans = inf;
    for(ll i = 1; i <= n; i++)
    {

        ll xx = lf[i-1]+rt[n]-rt[i];
        ans = min(ans,xx);
    }
    cout << ans;
}
