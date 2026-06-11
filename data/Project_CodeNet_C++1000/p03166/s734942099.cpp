#include <bits/stdc++.h>
#define ll long long
#define sz(a) int((a).size())
#define fr(i,n) for(int i=0;i<n;i++) 
#define rf(i,n) for(int i=1;i<=n;i++) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX INT_MAX 
#define f first
#define s second
using namespace std;
#define M 1000000007
int dp[100001];
int vis[100001];
void dfs(int node, vector<vector<int> > &v);
int main()
{
    int n,m;
    cin>>n>>m;
    std::vector<vector<int> > v(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
    }
    // for(int i=1;i<n;i++)
    // {
    //     for(int j=0;j<v[i].size();j++)
    //         cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i,v);
    }
    cout<<(*max_element(dp,dp+n+1))<<endl;
    return 0;
}

void dfs(int node, vector<vector<int> > &v)
{
    if(vis[node]==0)
        vis[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
            dfs(v[node][i],v);

        dp[node] = max(dp[node],1+dp[v[node][i]]);
    }
}