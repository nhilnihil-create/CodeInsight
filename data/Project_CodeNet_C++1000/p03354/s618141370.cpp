#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[100100];
int vis[100100];
vector<int>v,vec[100100];
map<int,int>mp;
void dfs(int src)
{
    vis[src]=1;
    mp[src]++;
    mp[arr[src]]++;
    v.push_back(src);
    for(int i=0; i<vec[src].size(); i++)
    {
        int child=vec[src][i];
        if(!vis[child])
            dfs(child);
    }
}
void init()
{
    for(auto x:v)
    {
        if(mp[x]==2)
            arr[x]=x;

    }
    mp.clear();
    v.clear();
}
int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(vec[i].size() && !vis[i])
        {
            dfs(i);
            init();
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==i)
            cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}
