#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define pb(x)                       push_back(x)
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;
ll n;
ll w[MAXN],s[MAXN],v[MAXN];
ll wa[MAXN],sa[MAXN],va[MAXN];
vector<pll> vec;
ll dp[20010];
ll dp2[20010];
ll ans;

int main()
{
    fast_io;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> w[i] >> s[i] >> v[i];
    }
    for(int i = 1;i <= n;i++){
        vec.push_back({w[i] + s[i],i});
    }
    sort(all(vec));
    for(int i = 0;i < n;i++){
        ll ind = vec[i].S;
        wa[i + 1] = w[ind];
        sa[i + 1] = s[ind];
        va[i + 1] = v[ind];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= sa[i];j++){
            dp2[wa[i] + j] = max(dp[j] + va[i],dp[wa[i] + j]);
        }
        for(int j = 1;j <= 20000;j++)
            dp[j] = max(dp[j],dp2[j]);
    }
    for(int i = 1;i <= 20000;i++){
        ans = max(ans,dp[i]);
    }

    cout << ans << endl;
}
