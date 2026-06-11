
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define mod 1000000007
#define ss second
#define ff first
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define vs vector<string>
#define all(x) x.begin(),x.end()
#define mii map<int,int>
#define vd vector<double>
#define deb(x) cout<<#x<<" -> "<<x<<endl
const int inf=0x3f3f3f3f3f3f3f3f;
#define MAXN 1000005

int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

void print(vi &v){
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
}

// <--------------------Code Begins Here-------------------->



int dfs(int i,vb &vis,vvi &adj,vi &dp){
	vis[i] = true;
	int maxi = 0;
	for(int x:adj[i]){
		if(!vis[x]){
			maxi = max(maxi,dfs(x,vis,adj,dp));
		}
		else{
			maxi = max(maxi,dp[x]);
		}
	}
	dp[i] = maxi + 1;
	return maxi+1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    vi ind(n+1);
    for(int i = 0; i < m; i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    }
    vb vis(n+1,false);
    vi dp(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		ans = max(ans,dfs(i,vis,adj,dp));
    	}
    }
    cout<<ans-1<<endl;
    return 0;
}