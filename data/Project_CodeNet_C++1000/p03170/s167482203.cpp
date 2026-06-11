#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e5+10;
long long dp[MAX],a[MAX],k,n;
long long sol(long long k)
{
    if (dp[k]!=-1) return dp[k];
    if (k==0) return dp[k]=0;
    long long tmp=0,i;
    for (i=1;i<=n;i++)
    {
        if (k-a[i]>=0)
        {
            if (sol(k-a[i])==0) {tmp=1;break;}
        }
    }
    return dp[k]=tmp;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    long long i;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>a[i];
    if (sol(k)) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
