#include <bits/stdc++.h>
using namespace std;
#define sz 100005
int n,a[sz],b[sz],c[sz];
int dp[sz][5];

int res(int ind,int ofStatus=0)
{
    if(ind==n)return 0;
    if(dp[ind][ofStatus]!=-1)return dp[ind][ofStatus];
    int r=INT_MIN;
    if(ofStatus!=1)
    {
        r=max(r,a[ind]+res(ind+1,1));
    }
    if(ofStatus!=2)
    {
        r=max(r,b[ind]+res(ind+1,2));
    }
    if(ofStatus!=3)
    {
        r=max(r,c[ind]+res(ind+1,3));
    }
    return dp[ind][ofStatus]=r;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];

    cout<<res(0)<<endl;

   return 0;
}
