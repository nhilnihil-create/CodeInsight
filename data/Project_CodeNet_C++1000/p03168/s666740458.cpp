#include <bits/stdc++.h>

using namespace std;
int n,i,j;
double dp0[6005];
double dp1[6005];
double ans,p;
int main()
{
    cin>>n;
    dp1[n]=1;
    for(i=1;i<=n;i++)
    {
        cin>>p;

        for(j=0;j<=2*n;j++)
        {
            dp0[j]=dp1[j];
            dp1[j]=0;
        }

        for(j=0;j<=2*n;j++)
        {
            if(j)
                dp1[j-1]+=dp0[j]*((double)1 - p);
            if(j<2*n)
                dp1[j+1]+=dp0[j]*p;
        }
    }

    for(i=n+1;i<=2*n;i++)
        ans+=dp1[i];

    cout.precision(12);
    cout<<ans;
    return 0;
}
