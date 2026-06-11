#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

ll visited[100010]={0},dp[100010]={0};

ll dfs(ll node,vector< vector <ll >> &adlist){
    if(visited[node]==1)
        return dp[node];
    visited[node]=1;
    if(adlist[node].size()==0)
    	return 0;
    ll maxi=0;
    for(ll i: adlist[node]){
        ll tmp=dfs(i,adlist);
        if(tmp>maxi)
            maxi=tmp;
    }
    return dp[node]=(1+maxi);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m ;
    vector< vector < ll > > adlist(n+1);
    for(ll i=0;i<m;++i){
        ll u,v;
        cin>> u >> v;
        adlist[u].push_back(v);
    }
    for(ll i=1;i<=n;++i){
        if(visited[i]==0)
            dp[i]=dfs(i,adlist);
    }
    ll ans=0;
    for(ll i=0;i<=n;++i){
        if(ans<dp[i])
            ans=dp[i];
    }
    cout<< ans ;
	return 0;
}
