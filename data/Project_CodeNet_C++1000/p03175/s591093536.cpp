#include<bits/stdc++.h>
#define ll long long
#define F(type, i, a, b) for(type i = a; i <= b; i ++)
#define RF(type, i, a, b) for(type i = a; i >= b;i --)
#define sz(a) sizeof(a)
#define deb(a) cerr<<" ["<<#a<<"->"<<a<<"] "
#define next_line cerr<<'\n'
#define all(a) a.begin(), a.end()
#define iter(it, s) for(auto it = s.begin(); it != s.end(); it ++)

using namespace std;

typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

//       1
//      / \ -> Tree
//     2   3
vector<vector<ll> > Tree(100001);
ll mod = 1e9 + 7LL;
vector<bool> vis(100001, false);
vector<pll> dp(vector<pll>(100001, {-1, -1}));

ll NumberOfways(ll st, ll color)
{
    if((color == 0LL) && (dp[st].first != -1LL))
        return dp[st].first;
    if((color == 1LL) && (dp[st].second != -1LL))
        return dp[st].second;
    vis[st] = true;
    ll ans = 1LL;
    for(ll child: Tree[st]){
        if(vis[child])
            continue;
        if(color == 0LL)
            ans *= (NumberOfways(child, 0LL) + NumberOfways(child, 1LL));
        else
            ans *= NumberOfways(child, 0LL);
        ans %= mod;
    }    
    (color == 0LL)?(dp[st].first = ans):(dp[st].second = ans);
    vis[st] = false;
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    F(ll, v, 1, n - 1){
        ll x,y;
        cin>>x>>y;
        Tree[x - 1].push_back(y - 1);
        Tree[y - 1].push_back(x - 1);
    }
    ll ans = (NumberOfways(0, 0));
    ans += NumberOfways(0, 1);
    ans %= mod;
    cout<<ans<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        freopen("Debug.txt", "w", stderr);
    #else
    #endif
    solve();
}
