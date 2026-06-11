#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = (int)1e7+9;
#define REP0(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<=n;i++)
#define F first
#define S second
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define inf (int)(1e18)
#define prec(x) fixed<<setprecision(x)<<x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int node,vi adj[],vi &dp,vb &vis){
    vis[node] = true;
    REP0(i,adj[node].size()){
        if(!vis[adj[node][i]]){
            dfs(adj[node][i],adj,dp,vis);
        }
        dp[node] = max(dp[node],1+dp[adj[node][i]]);
    }
}

int findLongestPath(vi adj[],int n){
    vi dp(n+1,0);
    vb vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,dp,vis);
        }
    }
    return *max_element(all(dp));
}

void solve(){
   int n,m;
   cin>>n>>m;
   vi  adj[n+1];
   REP0(i,m){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
   }
   cout<<findLongestPath(adj,n);
}


int main(){
    fastio;
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
        solve();
    }
    return 0;
}
