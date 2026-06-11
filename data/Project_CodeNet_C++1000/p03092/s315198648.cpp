#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5002;
int n,a,b,p[N];
LL f[N],g[N][N],h[N][N];
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++) cin>>p[i];
    p[n+1]=n+1;
    for (int i=0;i<n;i++)
    for (int j=i+2;j<=n+1;j++)
    {
        g[i][j]+=g[i][j-1];
        if (p[i]>p[j-1]) g[i][j]+=b;
    }
    for (int i=2;i<=n+1;i++)
    for (int j=i-2;j>=0;j--)
    {
        h[j][i]+=h[j+1][i];
        if (p[i]<p[j+1]) h[j][i]+=a;
    }
    //cout<<g[0][2]<<"\n";
    for (int i=1;i<=n+1;i++) f[i]=1e18;
    for (int i=1;i<=n+1;i++)
    {
        int mx=-1;
        for (int j=i-1;j>=0;j--)
        if (p[i]>p[j]&&p[j]>mx)
        {
            mx=p[j];
            f[i]=min(f[i],f[j]+g[j][i]+h[j][i]);
            //cout<<i<<" "<<j<<" "<<f[i]<<"\n";
        }
    }
    cout<<f[n+1];
    return 0;
}
