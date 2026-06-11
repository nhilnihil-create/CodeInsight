#include<bits/stdc++.h>
using namespace std;
int tmp,a[25][25],n, d[25][1<<21];
long long f[25][1<<21];

long long dp(int i,int used)
{
    if (i>n) return 1;
    if (d[i][used]!=0) return f[i][used]; d[i][used]=1;
    long long &res=f[i][used];
    for (int j=1;j<=n;j++)
    {
        if (a[i][j]==0 || ((used>>j)&1)) continue;
        res=(res+dp(i+1,used | (1<<j)))%1000000007;
    }
    return res;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    cout<<dp(1,tmp);
    return 0;
}
