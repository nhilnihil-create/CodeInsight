#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr ll INF=1000000000000000000;
int n,a,b,p[5010],q[5010];
ll dp[5010][10010];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    rep(i,n){
        cin>>p[i];
        q[p[i]-1]=i+1;
    }
    rep(i,n+1)rep(j,2*n+2)dp[i][j]=INF;
    dp[0][1]=0;
    rep(i,n){
        ll cur=INF;
        for(int j=1;j<=2*n+1;j++){
            if(j%2==1){
                chmin(cur,dp[i][j]);
                chmin(cur,dp[i][j-1]);
            }
            if(j>q[i]*2)chmin(dp[i+1][j],cur+a);
            if(j<q[i]*2)chmin(dp[i+1][j],cur+b);
            if(j==q[i]*2)chmin(dp[i+1][j],cur);
        }
    }
    ll ans=INF;
    rep(j,2*n+2)chmin(ans,dp[n][j]);
    cout<<ans<<endl;
    return 0;
}
