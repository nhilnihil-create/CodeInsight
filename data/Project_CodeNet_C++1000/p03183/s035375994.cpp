#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int w,s;
    long long v;
};
bool cmp(node x,node y)
{
    return (x.s+x.w)>(y.s+y.w);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,i,j,k;
    cin>>n;
    vector<node>arr(n);
    for(i=0;i<n;i++)
    {
        cin>>arr[i].w>>arr[i].s>>arr[i].v;
    }
    sort(arr.begin(),arr.end(),cmp);
    int sz=arr[0].s+arr[0].w;
    vector<long long>tmp(sz+1);
    vector<vector<long long> >dp(n+1,tmp);
    for(j=0;j<=sz;j++) dp[n][j]=0ll;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<=sz;j++)
        {
            dp[i][j]=0ll;
            if(arr[i].w<=j) dp[i][j]=arr[i].v+dp[i+1][min(j-arr[i].w,arr[i].s)];
            dp[i][j]=max(dp[i][j],dp[i+1][j]);
        }
    }
    long long ans=arr[n-1].v;
    for(i=0;i<n-1;i++)
    {
        ans=max(ans,arr[i].v+dp[i+1][arr[i].s]);
    }
    cout<<ans;
}
