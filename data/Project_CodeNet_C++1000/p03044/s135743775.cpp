#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int,long long int> > w[100005];
bool vis[100005];
int color[100005];


void bfs(long long int s)
{
    vis[s]=true;
    queue<long long int>q;
    q.push(s);
    while(!q.empty())
    {
        long long int x=q.front();
        q.pop();
        for(int k=0;k<w[x].size();k++)
        {
            long long int j=w[x][k].first;
            if(vis[j]==false)
            {
                vis[j]=true;
                q.push(j);
               if(w[x][k].second%2==0)
               {
                   color[j]=color[x];
               }
               else{
                color[j]=color[x]^1;
               }
            }
        }

    }
}

main()
{
    long long int n,i,j;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        long long int x,y,d;
        cin>>x>>y>>d;
         w[x].push_back({y,d});
         w[y].push_back({x,d});
    }

    color[1]=1;
    bfs(1);
    for(i=1;i<=n;i++)
    {
        cout<<color[i]<<endl;
    }
}

