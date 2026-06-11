#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define ll long long int
#define ull unsigned long long int
#define inf LONG_MAX;
using namespace std;
ll dp[100005], h[100005],n;
int main()
{
    fast_io
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    dp[2]=abs(h[1]-h[2]);
    for(int i=3;i<=n;i++)
        dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
    cout<<dp[n]<<endl;
}
