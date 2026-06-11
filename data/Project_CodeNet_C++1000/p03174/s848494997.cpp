#include <iostream>
#include <fstream>
using namespace std;
long long n,a[100][100],F[25][3000005];
long long DP(long long i,long long used)
{
    if (i==n) return 1;
    if (F[i][used]>-1) return F[i][used];

    long long &res=F[i][used];
    res=0;
    for (int j=0;j<=n-1;j++) {
        if (a[i][j]==0 || ((used>>j) & 1)) continue;
        res=(res+DP(i+1,used | (1<<j)))%1000000007;
    }
    return res;
}

int main()
{
    //freopen("MATCHING.INP","r",stdin);
    //freopen("MATCHING.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<=n-1;i++)
        for (int j=0;j<=n-1;j++)
            cin>>a[i][j];

    for (int i=0;i<=n-1;i++)
        for (int j=0;j<=3000000;j++)
            F[i][j]=-1;
    cout<<DP(0,0);
    return 0;
}
