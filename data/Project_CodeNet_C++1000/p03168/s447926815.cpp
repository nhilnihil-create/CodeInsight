#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

db dp[3000][1600];

db fun(int c,int h,db *a)
{
    if(h==0)return 1;
    if(c==0)return 0;
    if(dp[c][h]>-0.9)return dp[c][h];
    return dp[c][h]=a[c-1]*fun(c-1,h-1,a)+(1-a[c-1])*fun(c-1,h,a);
}
void solve()
{
    int n;
    cin>>n;
    db a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int h=(n+1)/2;
    memset(dp,-1,sizeof(dp));
    fun(n,h,a);
    cout<<fixed<<setprecision(10)<<dp[n][h];
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
