#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp map<int,int>
#define pp make_pair
#define endl "\n"
#define ll long long 
#define vi vector<int>
#define clock high_resolution_clock::now()

// auto duration = duration_cast<microseconds>(stop - start);  cout<<duration.count();

const int INF = 1e9+5;
const int mod = 1e9 + 7;


using namespace std;
using namespace std::chrono;



void dfs(vector<int>&dp, vector<bool>&vis, int node, vector<int>v[]){
    vis[node] = 1;
    for(int ver : v[node]){
    	
        if(!vis[ver]){
        dfs(dp, vis, ver, v);}

        dp[node] = max(dp[node], 1 + dp[ver]);
        
    }
}


int f(vector<int>v[], int n){
    vector<int>dp(n+1, 0);
   
    vector<bool>vis(n+1, false);
    for(int i=1; i<=n; i++)vis[i] =dp[i] = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i])dfs(dp, vis, i, v);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}
        
    

int main(){
	int n, m;
    cin>>n>>m;
    vector<int>v[n+1];
    int x, y;
    while(m--){
        cin>>x>>y;
        v[x].pb(y);
    }
    cout<<f(v, n)<<endl;

	return 0;
}
	
	