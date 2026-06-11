#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005

vector < pair < int , int > > a[N];
int vis[N];
int pos[N];
int valid = 1;

void dfs(int n, int cur)
{
    vis[n] = 1;
    pos[n] = cur; 
    for(int i=0;i<a[n].size();i++)
    {
        if(vis[a[n][i].first]==0)
        {
            dfs(a[n][i].first, cur+a[n][i].second);
        }
        else
        {
            if( pos[n] + a[n][i].second != pos[a[n][i].first] )
                valid = 0;
        }
    }
}


int32_t main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        a[u].push_back({v, w});
        a[v].push_back({u, -w});
    }

    for(int i=1;i<=n;i++)
        pos[i] = -1;

    int cur = 0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i, cur);
            cur+=1e10;
        }
    }

    if(valid == 0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    return 0;
}