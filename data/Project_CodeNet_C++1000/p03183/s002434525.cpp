#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n;
ll v[1001],w[1001],s[1001];
ll dp[1001][20022];
int ord[1001];
bool cmp(const int& l,const int& r){
    return min(s[l],s[r]-w[l])>min(s[r],s[l]-w[r]);
}
int main(){
    cin>>n;
    rep(i,n) cin>>w[i]>>s[i]>>v[i];
    rep(i,n) ord[i]=i;
    sort(ord,ord+n,cmp);
    rep(i,n)rep(j,20002){
        int id=ord[i];
        dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        if(j<=s[id]) dp[i+1][j+w[id]]=max(dp[i+1][j+w[id]],dp[i][j]+v[id]);
    }
    ll ans=0;
    rep(i,20002) ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}
