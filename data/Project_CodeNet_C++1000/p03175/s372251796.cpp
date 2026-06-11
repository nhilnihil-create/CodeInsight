#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=100001,MOD=1e9+7;
vector<ll> edg[NMAX];
ll dp[NMAX][2];
bool visited[NMAX];
void dfs(ll node){
    visited[node]=1;
    dp[node][0]=dp[node][1]=1;
    for(auto it : edg[node]){
        if(!visited[it]){
            dfs(it);
            dp[node][1]=(dp[node][1]*dp[it][0])%MOD;
            dp[node][0]=(dp[node][0]*(dp[it][0]+dp[it][1]))%MOD;
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1);
    cout<<(dp[1][0]+dp[1][1])%MOD;
    return 0;
}

///ABCDEFGHIJKLMNOPQRSTUVWXYZ
///11110111101010100000000000
