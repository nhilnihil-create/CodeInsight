#include <bits/stdc++.h>
using namespace std;


#define clr(arr,val) memset(arr,val ,sizeof arr)
typedef  long long ull;
typedef long long ll;


ll const oo=1e9 ;
int const SZ= (int)1e5+3;
const ll mod=(ll)1e9+7;


vector<int> adj[SZ];
//int arr[100];
int dp[SZ];
int n,m;

int solve(int i){

    int &ret=dp[i];
    if(~ret) return ret;
    int mx=0;
    for(int x: adj[i]){
        mx=max(mx,solve(x));
    }
    return ret=1+mx;
    
}
int main()
{
    
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v; 
        adj[u].push_back(v);
    }
    clr(dp,-1);
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,solve(i));
    }
    
    cout<<mx-1<<endl;
    
    return 0;
}