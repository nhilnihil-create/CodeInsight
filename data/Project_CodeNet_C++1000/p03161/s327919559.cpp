#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define ll long long int
#define ull unsigned long long int
#define inf LONG_MAX;
using namespace std;
ll dp[100005], h[100005],n,k;
int main()
{
    fast_io
    for(int i=2;i<=100000;i++)
        dp[i]=inf;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
            if(i+j<=n)
                dp[i+j]=min(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
    }
    cout<<dp[n]<<endl;
}
