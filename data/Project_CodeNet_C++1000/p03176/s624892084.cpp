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

ll n, MaxBen = 0LL;
vector<ll> dp(2e5 + 1, -1);
ll Maxval(ll st, vector<ll> &h, vector<ll> &a){
    ll val = a[st], maxIncr = 0LL;
    if(dp[st ] != -1LL)
        return dp[st];
    F(ll, i, 0, st - 1){
        if(h[i] <= h[st]){
            maxIncr = max(maxIncr, Maxval(i, h, a));
        }
    }
    val += maxIncr;
    dp[st] = val;
    MaxBen = max(MaxBen, val);
    return val;
}

ll Query(ll st, ll end, ll node, ll l, ll r, vector<ll> &Tree){
    if(st > end)
        return 0LL;
    if((r < st) || (end < l))
        return 0LL;
    if((l <= st) && (end <= r))
        return Tree[node];
    ll mid = (st + end) >> 1;
    return max( Query(st, mid, (node << 1), l, r, Tree), 
                Query(1LL + mid, end, (node << 1) + 1, l, r, Tree)); 
}

void update(ll st, ll end, ll node, ll indx, ll val, vector<ll> &Tree){
    if((indx < st) || (indx > end))
        return;
    if(st == end){
        Tree[node] = val;
        return;
    }
    ll mid = (st + end) >> 1;
    update(st, mid, (node << 1), indx, val, Tree);
    update(mid + 1LL, end, (node << 1) + 1, indx, val, Tree);
    Tree[node] = max(Tree[(node << 1)],
                     Tree[(node << 1) + 1]);
}

void solve()
{
    cin>>n;
    vector<ll> Height(n), Beauty(n), Tree((n << 2) + 1, 0);
    F(ll, i, 0, n - 1){
        cin>>Height[i];
    }
    F(ll, i, 0, n - 1){
        cin>>Beauty[i];
    }
    // RF(ll, i, n - 1, 0){
    //     Maxval(i, Height, Beauty);
    // }
    //We need to find the maximum value of dp 
    //in heights less than our height
    //For this we need that the heights are in increasing 
    //order ,so that we can query over a range easily and find the
    //maximum of them. For this we can use segment tree .For heights
    //That we don't wanna involve ,we can simply initialize them as 0
    F(ll, st, 0, n - 1){
        ll Maxincr = Query(0, n - 1, 1, 0, Height[st] - 2, Tree);
        dp[st] = Maxincr + Beauty[st];
        update(0, n - 1, 1, Height[st] - 1, dp[st], Tree);
        MaxBen = max(MaxBen, dp[st]);
    }
    cout<<MaxBen<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("Debug.txt", "w", stderr);
    #else
    #endif
    solve();
}
