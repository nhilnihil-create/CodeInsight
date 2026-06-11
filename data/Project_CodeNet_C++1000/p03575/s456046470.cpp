#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int mat[60][60],used[60][60],v[60];
int cnt,t,n,m,ans;
void dfs(int src)
{
    v[src]=t;
    cnt++;
    for(int i=1; i<=n; i++)
    {
        if(mat[src][i] && v[i]!=t)
            dfs(i);
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        mat[u][v]=1;
        mat[v][u]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(mat[i][j] && !used[i][j])
            {
                mat[i][j]=0;
                mat[j][i]=0;
                used[i][j]=1;
                used[j][i]=1;
                t++;
                cnt=0;
                dfs(1);
                mat[i][j]=1;
                mat[j][i]=1;
                if(cnt!=n)
                    ans++;
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
