// Sakhiya07 - Yagnik Sakhiya

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>

#define mp make_pair
#define bp __builtin_popcountll
#define MOD  1000000007
const int N = 200005;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
string s;
ll dp[N];
vector<ll> v;
ll solve1(ll id)
{
    if(id==0)    return 0;
    ll ans = dp[id];
    if(ans!=-1)   return ans;
    ans = 1e9;
    for(auto X:v)
    {
        if(X<=id)
        {
            ans = min(ans,1+solve1(id-X));
        }
    } 
    return dp[id] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    v.pb(1);
    ll temp = 6;
    while(temp<=n)
    {
        v.pb(temp);
        temp *= 6;
    }
    temp = 9;
    while(temp<=n)
    {
        v.pb(temp);
        temp *= 9;
    }
    sort(all(v));
    memset(dp,-1,sizeof(dp));
    ll ans = solve1(n);
    cout<<ans;
}

int main()
{
    FAST;
    ll t = 1;
  //  cin >> t;
    while(t--)
    {
        solve();
    }
}