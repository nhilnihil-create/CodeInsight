#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define pb push_back
using namespace std;
double dp[3001][3001];
double solve(double *a, int i, int x)
{
    if(x==0)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][x]>-0.9)
        return dp[i][x];
    return dp[i][x]=a[i-1]*solve(a,i-1,x-1)+(1-a[i-1])*solve(a,i-1,x);
}
int32_t main()
{
    int t;
    //cin>>t;
    //while(t--)
    {   
        int n;
        cin>>n;
        double a[3001];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<fixed<<setprecision(10)<<solve(a,n,(n+1)/2);
    }
}




