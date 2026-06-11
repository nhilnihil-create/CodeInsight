#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

#define INF 1e10

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    ll w,z; cin>>w>>z;
    vll a(n);
    rep(i,n) cin>>a[i];
    vector<vll> dp(n, vll(2));
    rep(i,n) dp[i][0]=0;
    rep(i,n) dp[i][1]=INF;
    RFOR(i,n-1,0){
        //X
        ll Y = (i==0)?z:a[i-1];
        dp[i][0] = max(dp[i][0], abs(Y-a[n-1]));
        FOR(j,i+1,n-1) dp[i][0] = max(dp[i][0], dp[j][1]);
        //Y
        ll X = (i==0)?w:a[i-1];
        dp[i][1] = min(dp[i][1], abs(X-a[n-1]));
        FOR(j,i+1,n-1) dp[i][1] = min(dp[i][1], dp[j][0]);
    }
    cout<<dp[0][0]<<"\n";
    return 0;
}
