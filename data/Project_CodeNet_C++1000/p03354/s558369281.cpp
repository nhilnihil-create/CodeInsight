#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>graph[MAX];
int arr[MAX];
int vis[MAX];
vector<int>v;
map<int,int>mp;
void dfs(int src)
{
    vis[src]=1;
    mp[src]++;
    mp[arr[src]]++;
    v.push_back(src);
    for(int i=0; i<graph[src].size(); i++)
    {
        int child=graph[src][i];
        if(!vis[child])
            dfs(child);
    }
}
void fix()
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
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(graph[i].size() && !vis[i])
        {
            dfs(i);
            fix();
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
