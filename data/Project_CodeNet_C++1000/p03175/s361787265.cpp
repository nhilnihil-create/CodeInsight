#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
vector<ll> v[100010];
ll dp[100010][2]={};
ll dfs(ll i,ll par,ll color){
    if(dp[i][color]!=0) return dp[i][color];
    dp[i][color]=1;
    for(auto x:v[i]){
        if(x==par) continue;
        if(color==0) dp[i][color]*=(dfs(x,i,0)+dfs(x,i,1));
        if(color==1) dp[i][color]*=dfs(x,i,0);
        dp[i][color]%=mod;
    }
    return dp[i][color];
}

int main(void){
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<(dfs(0,-1,0)+dfs(0,-1,1))%mod<<endl;
}