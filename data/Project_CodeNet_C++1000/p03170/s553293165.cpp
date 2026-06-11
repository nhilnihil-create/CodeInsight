#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
ll n;
ll dp[100001];
int solve(int k,vector<ll>&a){
    if(dp[k]!=-1){
        return dp[k];
    }
    if(k==0){
        return dp[k]==0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<=k && solve(k-a[i],a)==0){
            ans=1;
            break;
        }
    }
    return dp[k]=ans;
}
int main() {
    FIO;
    //test
    {
        ll k;
        cin>>n>>k;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        solve(k,a)?cout<<"First":cout<<"Second";
        cout<<"\n";
    }
	return 0;
}
