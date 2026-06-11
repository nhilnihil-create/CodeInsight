#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX=100001;

typedef pair<int,int> pii;
vector<pii> edge[MAX];
bool visited[100001];
int dist[100001];

bool dfs(int v)
{
    visited[v]=true;
    for(int j=0;j<edge[v].size();j++)
    {
        int next=edge[v][j].first;
        int cost=edge[v][j].second;
        if(!visited[next])
        {
            dist[next]=dist[v]+cost;
            if(!dfs(next))
                return false;

        }
        else
        {
            if(dist[next]!=dist[v]+cost)
                return false;
        }



    }
    return true;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if(m==0)
    {
        printf("Yes");
        return 0;
    }
    while(m--)
    {
        int l,r,val;
        scanf("%d %d %d",&l,&r,&val);
        edge[l].push_back(make_pair(r,val));
        edge[r].push_back(make_pair(l,-val));
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dist[i]=0;
            if(!dfs(i))
            {
                printf("No");
                return 0;
            }

        }
    }
    printf("Yes");
    return  0;
}