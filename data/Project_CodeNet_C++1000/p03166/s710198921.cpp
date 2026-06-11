#include <iostream>
#include <vector>
using namespace std;
long n,m;
vector <long> F[100005];
bool Free[100005];
long G[100005];
long DFS(long u)
    {
        long i,v;
        if (G[u]!=0) return G[u];
        for (i=0;i<F[u].size();++i)
        {
            v=F[u][i];
            if (Free[v]==true)
            {
                Free[v]=false;
                G[u]=max(G[u],DFS(v)+1);
            }
            Free[v]=true;
        }
        return G[u];
    }
int main()
    {
        long i,t1,t2;
        cin>>n>>m;
        for (i=1;i<=m;++i)
        {
            cin>>t1>>t2;
            F[t1].push_back(t2);
        }
        for (i=1;i<=n;++i) F[0].push_back(i);
        fill(Free+1,Free+1+n,true);
        cout<<DFS(0)-1;
        return 0;
    }
