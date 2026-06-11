#include <bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define Rrep(i,y,x) for(ll i=y;i>x;i--)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define print(x) cout << (x) << endl;
typedef long long ll;
using namespace std;
ll mod=1e9+7;

int main(){
    ll N,A,B;
    ll inf=1e15;
    cin>>N>>A>>B;
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,inf));
    dp[0][0]=0;
    vector<ll> P(N);
    rep(i,0,N){
        ll b;
        cin>>b;
        P.at(i)=b;
    }
    rep(i,1,N+1){
        rep(j,0,N+1){
            if (j < P[i-1]){
                dp[i][P[i-1]]=min(dp[i][P[i-1]],dp[i-1][j]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+A);
            }
            else{
                dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
            }
        }
    }
    ll ans=inf;
    rep(i,0,N+1){
        ans=min(ans,dp[N][i]);
    }
    print(ans);

}