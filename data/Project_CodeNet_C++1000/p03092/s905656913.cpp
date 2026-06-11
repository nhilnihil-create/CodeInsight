#include <bits/stdc++.h>
#define N 5002
using namespace std;
long long n,a,b,i,j,f[N],sl,ma,p[N];
int main()
{
   // freopen("ntu.inp","r",stdin);
   // freopen("ntu.out","w",stdout);
    cin>>n>>a>>b;
    for(i=1;i<=n;i++) cin>>p[i];
    p[n+1]=n+1;
    for(i=1;i<=n+1;i++)
    {
        ma=-1; sl=0; f[i]=round(1e18);
        for(j=i-1;j>=0;j--)
            if(p[j]>p[i]) sl++;
            else
            {
                if(ma<p[j]) f[i]=min(f[i],f[j]+sl*a+(i-j-1-sl)*b);
                ma=max(ma,p[j]);
            }
    }
    cout<<f[n+1];
}
