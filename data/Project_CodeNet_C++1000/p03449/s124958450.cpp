#include <bits/stdc++.h>
using namespace std;

int a[2][110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=0;i<2;i++)for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        a[i][j]+=a[i][j-1];
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[0][i]+a[1][n]-a[1][i-1]);
    }

    cout<<ans<<"\n";

    return 0;
}
