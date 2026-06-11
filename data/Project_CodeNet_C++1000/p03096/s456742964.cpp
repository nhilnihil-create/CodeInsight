#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

ll dp[200010] = {};

signed main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(200010, vector<ll>(0));
    vector<PL> k(0);
    rep(i, n)
    {
        ll x;
        cin >> x;
        v[x].pb(i);
    }

    repi(i, 1, 200001)
    {
        rep(j, siz(v[i]) - 1)
        {
            if (v[i][j + 1] - v[i][j] > 1)
            {
                k.emplace_back(v[i][j], v[i][j + 1]);
            }
        }
    }

    sort(all(k));

    dp[0] = 1;

    ll ind=0;
    rep(i, n)
    {
        while(ind <siz(k) && k[ind].fi<=i){
            dp[k[ind].se]+=dp[k[ind].fi];
            dp[k[ind].se]%=mod;
            ind++;
        }
        dp[i+1]+=dp[i];
        dp[i+1]%=mod;
        
    }

    cout<<dp[n-1]%mod<<endl;
}