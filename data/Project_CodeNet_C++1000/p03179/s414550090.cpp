#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
string s;
int n,f[3005][3005],sum[3005];
//f[i][j] la so hoan vi thoa man co do dai i xep vao i-1 dau co so cuoi cung xep vao hoan vi la j
int main()
{
    cin>>n>>s;
    //for(int i=0;i<=n;i++)
    f[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        sum[0]=0;
        for(int j=1;j<=i;j++)
           sum[j]=(sum[j-1]+f[i-1][j])%MOD;
        for(int j=1;j<=i;j++)
        {
            if ('>'==s[i-2])
            {
                f[i][j]=(sum[i]-sum[j-1]+MOD)%MOD;
               // for(int k=j;k<=i;k++)
                    //f[i][j]+=f[i-1][k],f[i][j]%=MOD;
            }
            else//<
            {
                f[i][j]=sum[j-1]%MOD;
                //for(int k=j-1;k>0;k--)
                    //f[i][j]+=f[i-1][k],f[i][j]%=MOD;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=(res+f[n][i])%MOD;
    cout<<res;
/*
    for(int i=1;i<=n;i++)
    {
        cout<<'\n';
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<' ';
    }
*/
    return 0;
}
