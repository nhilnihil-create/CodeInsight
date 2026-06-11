#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll n,m;
vector<ll>x,y,z,ux,uy,uz;

ll solve(vector<ll>&a,vector<ll>&b,vector<ll>&c){
    ll res = 0;
    vector<ll>p(n);
    rep(i,n){
        p[i]=a[i]+b[i]+c[i];
    }
    ll dp[1010][1010];
    rep(i,1010)rep(j,1010)dp[i][j]=-INF;
    dp[0][0]=0;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i<j)continue;
            chmax(dp[i+1][j],dp[i][j]);
            chmax(dp[i+1][j+1],dp[i][j]+p[i]);
        }
    }
    return dp[n][m];
}

int main(){
    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    ux.resize(n);
    uy.resize(n);
    uz.resize(n);
    rep(i,n)cin>>x[i]>>y[i]>>z[i];
    rep(i,n){
        ux[i]=-x[i];
        uy[i]=-y[i];
        uz[i]=-z[i];
    }
    ll ans = 0;
    chmax(ans,solve(x,y,z));
    chmax(ans,solve(x,y,uz));
    chmax(ans,solve(x,uy,z));
    chmax(ans,solve(ux,y,z));
    chmax(ans,solve(x,uy,uz));
    chmax(ans,solve(ux,uy,z));
    chmax(ans,solve(ux,y,uz));
    chmax(ans,solve(ux,uy,uz));

    cout << ans << endl;

    return 0;
}
