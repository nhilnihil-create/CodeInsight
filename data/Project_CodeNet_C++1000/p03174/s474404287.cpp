#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
vector<vector<ll>> dp;
vector<vector<ll>> v;
ll solve(ll men, ll women, ll mncnt, ll wmcnt, ll n){
    if(mncnt==n && wmcnt==n)
        return 1;
    if(mncnt==n || wmcnt==n)
        return 0;
    if(dp[men][women]!=-1)
        return dp[men][women];
    dp[men][women]=0;
    for(int i=0;i<n;i++){
        if(v[men][i]==1 && (women&(1<<i))==0){
            dp[men][women]+=solve(men+1,(women|(1<<i)),mncnt+1,wmcnt+1,n);
            dp[men][women]%=NUM;
        }
    }
    dp[men][women]%=NUM;
    return dp[men][women];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    v.assign(n+1,vector<ll>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    ll tot_mask = (1<<n)-1;
    dp.assign(n+1,vector<ll>(tot_mask+1,-1));
    cout<<solve(0,0,0,0,n)<<endl;
    return 0;
}
