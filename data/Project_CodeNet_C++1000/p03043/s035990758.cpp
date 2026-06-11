#include <bits/stdc++.h>
using namespace std;
int main()
{
    setprecision(18);
    int n,k;
    cin>>n>>k;
    double ans=0.0;
    for(int i=1;i<=min(n,k-1);i++)
    {
        int cur=i;
        int cnt=0;
        while(cur<k)
        {
            cur=cur*2;
            cnt++;
        }
        double curAns=(1.0/(1.0*n));
        for(int j=0;j<cnt;j++)
        {
            curAns=curAns*(0.5);
        }
        ans+=curAns;
    }
    for(int i=min(n,k-1)+1;i<=n;i++)
    {
        double curAns=(1.0/(1.0*n));
        ans+=curAns;
    }
    cout<<setprecision(18)<<ans<<"\n";
    return 0;
}