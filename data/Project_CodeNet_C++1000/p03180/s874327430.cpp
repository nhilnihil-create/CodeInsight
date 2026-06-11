#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[20][20],d[(1<<16)],F[(1<<16)];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i-1][j-1];
        }
    }
    int t=(1<<n)-1;
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(((1&(i>>j))==1)&&((1&(i>>k))==1))d[i]+=a[j][k];
            }
        }
        //cout<<d[i]<<'\n';
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=i;j>=0;j=((j-1)&i))
        {
            F[i]=max(F[i],F[j]+d[i^j]);
            if(j==0)break;
        }
    }
    cout<<F[t];
}
