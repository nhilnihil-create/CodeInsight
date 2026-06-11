#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
ll a[410],sum[410],dp[410][410];

ll fun(int x,int y)
{
    if(x==y)return 0;
    if(dp[x][y]>-1)return dp[x][y];
    ll ans=1e15;
    for(int i=0; i<(y-x); i++){
        ans=min(fun(x,x+i)+fun(x+i+1,y)+sum[y+1]-sum[x],ans);
    }
    return dp[x][y]=ans;
}
void solve()
{
    int n;
    cin>>n;
    sum[0]=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum[i+1]=a[i]+sum[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<fun(0,n-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
