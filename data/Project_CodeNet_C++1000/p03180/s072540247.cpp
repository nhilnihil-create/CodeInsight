#include <bits/stdc++.h>
using namespace std;
vector <int> vec[(1<<16)+1];
long long n,i,j,a[101][101],sum[(1<<16)+1],f[(1<<16)+1],tt,cnt,d[(1<<16)+1];
void BFS(int s)
{
    queue <int> q;
    cnt++;
    q.push(s); d[s]=cnt;
    while(q.size()>0)
    {
        int u=q.front(); q.pop();
        for(int i=0;i<vec[u].size();i++)
        {
            int v=u+(1<<vec[u][i]);
            if(d[v]<cnt)
            {
                q.push(v); d[v]=cnt;
             //   cerr<<f[s]+sum[v-s]<<'\n';
                f[v]=max(f[v],f[s]+sum[v-s]);
            }
        }
    }
}
int main()
{
    //freopen("group.inp","r",stdin);
    //freopen("group.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) cin>>a[i][j];
    for(tt=0;tt<(1<<n);tt++)
    {
        for(i=0;i<n;i++)
            if(!((tt>>i)&1)) vec[tt].push_back(i);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(((tt>>i)&1) && ((tt>>j)&1)) sum[tt]+=a[i][j];
    }
    f[tt]=0;
    for(tt=0;tt<(1<<n);tt++) BFS(tt);
    cout<<f[(1<<n)-1];
}
