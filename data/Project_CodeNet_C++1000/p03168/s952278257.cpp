#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;

db dp[3000][1600];

db fun(int c,int h,db *a)
{
    if(c==0 && h==0)return 1;
    else if(c<h) return 0;
    if(dp[c][h]!=0)return dp[c][h];
    db p=0;
    if(h==0){
        p=a[c-1]*fun(c-1,h,a)+(1-a[c-1])*fun(c-1,h,a);
    }
    else{
        p=a[c-1]*fun(c-1,h-1,a)+(1-a[c-1])*fun(c-1,h,a);
    }
    return dp[c][h]=p;
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
    memset(dp,0,sizeof(dp));
    fun(n,h,a);
    cout<<setprecision(10)<<dp[n][h];
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
