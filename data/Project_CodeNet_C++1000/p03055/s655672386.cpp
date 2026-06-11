#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define pll pair<ll,ll>
#define NMAX 200001

using namespace std;
typedef long long ll;
typedef long double ld;
int dist[NMAX];
bool win[NMAX];
vector<int>v[NMAX];
void DFS(int nod)
{
    for(auto &vec:v[nod])
    {
        if(dist[vec]==0)
        {
            dist[vec]=dist[nod]+1;
            DFS(vec);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int x,y,i,n;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dist[1]=1;
    DFS(1);
    x=1;
    for(i=1;i<=n;i++)
    {
        if(dist[i]>dist[x])
        {
            dist[x]=0;
            x=i;
            continue;
        }
        dist[i]=0;
    }
    dist[x]=1;
    DFS(x);
    int ma=0;
    for(int i=1;i<=n;i++)
    {
        ma=max(ma,dist[i]);
    }
    win[0]=0;
    win[1]=1;
    win[2]=0;
    for(int i=3;i<=ma;i++)
    {
        if(!win[i-1] || !win[i-2])
            win[i]=1;
        else
            win[i]=0;
    }
    if(win[ma]==1)
    {
        cout<<"First"<<'\n';
    }
    else
    {
        cout<<"Second"<<'\n';
    }
    
    return 0;
}