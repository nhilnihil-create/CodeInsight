#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b;
    cin>>a>>b;

    int ans=0;

    for(int i=1;i<=9;i++)for(int j=0;j<=9;j++)for(int k=0;k<=9;k++)
    {
        int n=i*10000+j*1000+k*100+j*10+i;
        if(a<=n&&n<=b)ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
