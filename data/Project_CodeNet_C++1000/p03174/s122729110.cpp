#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod =1000000007;
ll  dp[25][1<<22];
int a[25][25];

ll fun(int m,int w,int n){
    if(m==n){
        if(w==0)return 1;
        else return 0;
    }
    if(dp[m][w]>-1)return dp[m][w];
    ll ans=0;
    for(int i=0; i<n; i++){
        bool avl=((1<<i)&(w));
        if(avl && a[m][i]==1){
            ans+=fun(m+1,((1<<i)^(w)),n);
            ans%=mod;
        }
    }
    return dp[m][w]=ans;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    fun(0,(1<<n)-1,n);
    cout<<dp[0][(1<<n)-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
