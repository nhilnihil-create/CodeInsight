#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
ll n;
ll a[401];
ll prefix[401];
ll dp[401][401];
ll calc(ll a,ll b){
    if(a>b){
        return LONG_MAX;
    }
    return prefix[b]-prefix[a-1];
}
ll solve(int l,int r){
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(l==r){
        return dp[l][r]=0;
    }
    if(l+1==r){
        return dp[l][r]=a[l]+a[r];
    }
    ll best=LONG_MAX;
    for(int i=l;i<r;i++){
        ll cand=solve(l,i)+solve(i+1,r)+calc(l,r);
        best=min(best,cand);
    }
    return dp[l][r]=best;
}
int main() {
    FIO;
    //test
    {
       cin>>n;
       for(int i=1;i<=n;i++){
           cin>>a[i];
       }
       prefix[0]=0;
       for(int i=1;i<=n;i++){
           prefix[i]=prefix[i-1]+a[i];
       }
       memset(dp,-1,sizeof(dp));
       cout<<solve(1,n)<<endl;
    }
	return 0;
}
