#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+7;
const int INF=(1<<30);
int dist[MAXN],n;
vector<pair<int,int> > G[MAXN];
bool dfs(int v)
{
    bool ok=1;
    for (int i=0;i<G[v].size()&&ok;i++)
    {
        pair<int,int> u=G[v][i];
        if (dist[u.first]==-INF)
        {
            dist[u.first]=dist[v]+u.second;
            ok&=dfs(u.first);
        }
        else if (dist[u.first]!=dist[v]+u.second)
        {
            ok=0;
        }
    }
    return ok;
}
int main()
{
    ios::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    for (int i=0;i<m;i++)
    {
        int l,r,x;
        cin >> l >> r >> x;
        --l,--r;
        G[l].push_back(make_pair(r,x));
        G[r].push_back(make_pair(l,-x));
    }
    fill(dist,dist+n,-INF);
    bool ok=1;
    for (int i=0;i<n&&ok;i++)
    {
        if (dist[i]==-INF)
            dist[i]=0,ok&=dfs(i);
    }
//    for (int i=0;i<n;cout <<dist[i++]<<" ");
//    cout << endl;
    cout <<(ok?"Yes":"No")<<endl;
    return 0;
}
