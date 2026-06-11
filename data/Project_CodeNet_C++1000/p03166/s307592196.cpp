/*
Created by Rishu Sahu @ covid 20-20
*/
/*
*****************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pai pair<int,int>
#define pal pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,a,b) for(int i=a;i<=b;i++)
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define vi vector<int>
#define vl vector<ll>
#define mpl map<ll,ll>
#define mpi map<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int mod = 1e9+7;
const int INF = INT_MAX;

vi adj[100005];
int ind[100005];
int longest[100005];

int dfs(int start){
    if(longest[start]!=-1) return longest[start];
    int child=0;
    for(auto x:adj[start]){
        child=max(child,dfs(x));
    }
    return longest[start]=child+1;
}

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        //adj[v].pb(u);
        ind[v]++;
    }
    int ans=0;
    memset(longest,-1,sizeof(longest));
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            ans=max(ans,dfs(i));
           // cout<<i<<endl;
        }
    }
   // cout<<endl;
    cout<<ans-1<<endl;
}

int main(){
    solve();
}
