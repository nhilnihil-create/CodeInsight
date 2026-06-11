#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,inf=1e18;
ll dp[N],p[N],n,A,B;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>A>>B;
    for (int i=1;i<=n;i++) cin>>p[i],dp[i]=inf;
    dp[n+1]=inf;
    p[n+1]=n+1;
    for (int i=0;i<=n;i++)
    {
        ll cnt=0;
        for (int j=i+1;j<=n+1;j++)
            if (p[j]>p[i]) dp[j]=min(dp[j],dp[i]+(j-i-1-cnt)*A+cnt*B);
            else cnt++;
    }
    cout<<dp[n+1];
    return 0;
}
