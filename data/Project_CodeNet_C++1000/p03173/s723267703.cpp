																																																																																																																																																																																																																																																																																																																																																										#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

const ll INF = 1E18+5;
const ll mod = 1E9+7;

int main(){
    int n;
    cin>>n;
    int i, j, k;
    vector<ll> a(n+1);
    a[0] = 0;
    for(i = 1; i <= n; ++i)
        cin>>a[i];
    ll dp[n+1][n+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j] = INF;
    for(i=1;i<=n;i++)
        dp[i][i] = 0;
//    for(i=1;i<=n-1;i++)
//        dp[i][i+1] = a[i]+a[i+1];
    ll pre[n],len = 0;
    pre[0] = 0;
    for(i=1;i<=n;i++)
        pre[i] = pre[i-1] + a[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=j;k<j+i;k++)
            {
                if(j+i>n)
                    break;
                dp[j][j+i] = min(dp[j][j+i],dp[j][k]+pre[j+i]-pre[j-1]+dp[k+1][j+i]);
            }
        }
    }
    cout<<dp[1][n];
}


