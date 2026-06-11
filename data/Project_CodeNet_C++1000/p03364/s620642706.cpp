#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=605;
ull base=233,inv=7204522363551799129;
ull f[N],invf[N];
int n;
char a[N][N];
ull hsr[N][N],hsc[N][N];
int main()
{
    f[0]=invf[0]=1;
    for(int i=1;i<N;i++) f[i]=f[i-1]*base,invf[i]=invf[i-1]*inv;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        a[i+n][j+n]=a[i+n][j]=a[i][j+n]=a[i][j];
    for(int i=1;i<=n+n;i++)
        for(int j=1;j<=n+n;j++)
    {
        for(int k=0;k<n;k++)
        {
            if(i+k<=n+n) hsr[i][j]+=(a[i+k][j]-'a'+1)*f[k+1];
            if(j+k<=n+n) hsc[i][j]+=(a[i][j+k]-'a'+1)*f[k+1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        bool flag=true;
        for(int k=0;k<n;k++)
        {
            if(hsr[i][j+k]!=hsc[i+k][j])
            {
                flag=false;break;
            }
        }
        ans+=flag;
    }
    printf("%d\n",ans);
}
