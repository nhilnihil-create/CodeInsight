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

typedef pair<ll ,ll > pii;
typedef pair<ll,ll> pll;

#define INF 2e18
vector<vector<ll> > dp(401, vector<ll> (401, -1LL));
vector<ll> prefixSums(401, 0LL);

ll MinCost(ll  st, ll  end, vector<ll > &arr){
    if(st == end)
        return 0LL;
    if(dp[st][end ] != -1LL)
        return dp[st][end];
    ll ans = INF;
    ll mergeCost = (st == 0LL)?(prefixSums[end]):(prefixSums[end] - prefixSums[st - 1]); 
    F(ll , mark, st, end - 1LL){
        ans = min(ans, mergeCost + MinCost(st, mark, arr) + MinCost(mark + 1, end, arr));
    }
    dp[st][end] = ans;
    return ans;
}

void solve()
{
    ll  n;
    cin>>n;
    vector<ll > arr(n);
    F(ll , i, 0LL, n - 1LL)
        cin>>arr[i];
    prefixSums[0] = arr[0];
    F(int, i, 1LL, n - 1LL)
        prefixSums[i] = arr[i] + prefixSums[i - 1];
    cout<<MinCost(0LL, n - 1LL, arr);
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
