// And Then the GOD Entered..   
#include<bits/stdc++.h>
 using namespace std;
 
typedef long long int ll;
#define endl "\n"
#define fi first
#define sec second 
#define pb push_back
#define test cout<<"debuged\n";
#define INF ll(1e18)
#define MOD 1000000007
#define debug(x) cout<<x<<"\n";
#define pll pair<ll,ll>
#define mp make_pair
#define Minato_Namikaze ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define MAX 200015

struct node
{
    ll w;
    ll v;
    ll s;
};

ll n;
node a[MAX];
ll dp[1005][20005];

bool cmp(node &x, node &y)
{
    return (x.s + x.w) < (y.s + y.w);
}

ll solve(ll idx, ll wei)
{
    if(idx == n)
        return 0;
    ll &ans = dp[idx][wei];
    if(ans != -1)
        return ans;
    ans = solve(idx + 1, wei);
    if(a[idx].s >= wei)
        ans = max(ans, solve(idx + 1, wei + a[idx].w) + a[idx].v);
    return ans;
}

int main()
{
    Minato_Namikaze
 
    
    cin >> n;
    ll mx = -1;
    for(ll i = 0; i < n; ++i)
    {
        cin >> a[i].w >> a[i].s >> a[i].v;
        mx = max(mx, a[i].w);
    }
    sort(a, a + n, cmp);
    for(ll i = 0; i < n + 3; ++i)
        for(ll j = 0; j < 20001 + 3; ++j)
            dp[i][j] = -1;
    cout << solve(0,0); 
}