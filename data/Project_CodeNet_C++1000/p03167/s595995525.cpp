#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
#include <fstream>
using namespace std;
vector<ll> adj[100005];
ll vis[100005];
stack<ll> st;
void dfs(ll x)
{
    vis[x]=1;
    for(ll i=0;i<adj[x].size();i++)
        if(!vis[adj[x][i]])
        dfs(adj[x][i]);
    st.push(x);
}
int main()
{
    //  freopen("timber_input.txt", "r", stdin);
   // freopen("out3_test.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--) {
    ll n,m,i,j;
    cin>>n>>m;
    char arr[n+1][m+1];
    ll dp[n+1][m+1];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>arr[i][j];
    dp[0][0]=1;
    for(i=1;i<n;i++)
        if(arr[i][0]=='#')
        dp[i][0]=0;
    else
        dp[i][0]=dp[i-1][0];
    for(i=1;i<m;i++)
        if(arr[0][i]=='#')
        dp[0][i]=0;
    else
        dp[0][i]=dp[0][i-1];
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        if(arr[i][j]=='#')
        dp[i][j]=0;
    else
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%hell;
    cout<<dp[n-1][m-1];
    }

}
