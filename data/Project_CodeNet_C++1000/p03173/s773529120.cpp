#include<bits/stdc++.h>
using namespace std;
long long dp[401][401];
long long pre[401];

#define ll long long
#define f(i,n) for(ll i=0;i<n;i++)
ll min(ll a, ll b){return (a<b)?a:b;}
ll a[401];
ll solve(ll l, ll r){
        // if(l>r)return 0;
        if(l==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        dp[l][r]=1e18;
        for(ll i=l;i<r;i++){
                dp[l][r]=min(dp[l][r],solve(l,i)+solve(i+1,r)+pre[r]-pre[l-1]);
        }
        return dp[l][r];
}
int main() {
        ll n;
        cin>>n;
        // long a[n];
        f(i,n)cin>>a[i];
        // for( i,n)cin>>a[
                memset(dp,-1,sizeof dp);
                        pre[0]=a[0];
        for(ll i=1;i<n;i++){
                pre[i]=pre[i-1]+a[i];
        }
        solve(0,n-1);
        // ]
        cout<<dp[0][n-1]<<endl;

        return 0;

}
