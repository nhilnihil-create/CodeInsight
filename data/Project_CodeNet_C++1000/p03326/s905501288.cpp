#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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

#define INF 1e18

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vll> v(3,vll(n));
    rep(i,n){
        rep(j,3) cin>>v[j][i];
    }
    ll ans=-INF;
    vector<vll> dp(n+1,vll(m+1));
    rep(c,8){
        rep(i,n+1)rep(j,m+1) dp[i][j] = -INF;
        dp[0][0] = 0;
        rep(i,n)rep(j,m+1){
            if (j>0){
                ll temp=0;
                rep(k,3){
                    if (c>>k&1) temp += v[k][i];
                    else temp -= v[k][i];
                }
                dp[i+1][j] = max(dp[i][j],dp[i][j-1]+temp);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
        chmax(ans,dp[n][m]);
    }
    cout<<ans<<endl;
    return 0;
}
