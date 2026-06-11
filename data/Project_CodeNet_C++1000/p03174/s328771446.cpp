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

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, arr[21][21], mod = 1e9 + 7;
//Whenever a subset is a variable then we can represent it
//through masks(basically its a number whose set bits shows selected numbers)
//It helps to represent a subset of a set.
//As of here though it depends on where we start in the array
//it also depends on the womens already selected i.e 
//the set of women already selected , which could be easily represented
//by a mask(instead of a boolean array) as N is too small (i.e 21)
ll NumberOfways(ll st, ll mask, vector<vector<ll> > &dp){
    if(st == n)
        return 1LL;
    if(dp[st][mask] != -1)
        return dp[st][mask];
    ll count = 0LL;
    F(ll, i, 0, n - 1){
        if((arr[st][i]) && (!(mask & (1 << i)))){ 
            count += NumberOfways(st + 1, mask | (1 << i), dp);
            count %= mod;
        }
    }
    dp[st][mask] = count;
    return count;
}

void solve()
{
    cin>>n;
    F(ll, i, 0, n - 1){
        F(ll, j, 0, n - 1){
            cin>>arr[i][j];
        }
    }
    vector<vector<ll> > dp(n, vector<ll>(1 << n, -1));
    cout<<NumberOfways(0, 0, dp);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        // freopen("Debug.txt", "w", stderr);
    #else
    #endif
    solve();
}
