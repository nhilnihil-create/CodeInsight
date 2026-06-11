#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
ll dp[MAX][2];
void dfs(ll a, ll par, vector<ll> v[]){
    dp[a][0]=dp[a][1]=1;
    for(auto x : v[a]){
        if(x==par)
            continue;
        dfs(x,a,v);
        dp[a][0]=dp[a][0]*(dp[x][0]+dp[x][1])%NUM;
        dp[a][1]=dp[a][1]*dp[x][0]%NUM;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,a,b;
    cin>>n;
    vector<ll> v[n+1];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0,-1,v);
    cout<<(dp[0][0]%NUM+dp[0][1]%NUM)%NUM<<endl;
    return 0;
}
