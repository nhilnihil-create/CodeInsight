#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int nax=1e5+5;
const int mod=1e9+7;
vector<int> edges[nax];

ll mul(ll a,ll b){
    return(a*b)%mod;
}

pair<ll,ll> dfs(int u,int prev){
    ll all_white=1; //no of ways to paint with black color
    ll sth_is_black=0;
    for(auto v:edges[u]){
        if(v!=prev){
            pair<ll,ll> res=dfs(v,u);
            sth_is_black=(mul(all_white,res.first)+mul(sth_is_black,(res.first+res.second)%mod))%mod;
            all_white=mul(all_white,res.second);
        }
    }
    return {all_white,(all_white+sth_is_black)%mod};
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
   pair<ll,ll> ans= dfs(1,-1);
   ll answer=(ans.first+ans.second)%mod;
   cout<<answer;
}
