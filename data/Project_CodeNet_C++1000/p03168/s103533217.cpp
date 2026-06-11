#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define pii pair<int,int>
const int mod=1e9+7;
int n;
long double solve(int i,int j,long double* p,vector<vector<long double>> &dp,vector<vector<bool>> &vis){
    //cout<<i<<" "<<j<<"\n";
    if(i>=n) return 1;
    if(j<=0) return 1;
    if(j>n-i) return 0;
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=1;
    if(n-i==j){
        //cout<<i<<"\n";
        dp[i][j]=p[i]*solve(i+1,j-1,p,dp,vis);
    }
    else{
        dp[i][j]=p[i]*solve(i+1,j-1,p,dp,vis)+((1-p[i])*(solve(i+1,j,p,dp,vis)));
    }
    //cout<<dp[i][j]<<"\n";
    return dp[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
#endif
    cin>>n;
    long double p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        //cout<<p[i]<<" ";
    }
    //cout<<"\n";
    cout<<fixed<<setprecision(10);

    //memset(dp,-1,sizeof(dp));
    vector<vector<long double>> dp((n+1),vector<long double>((n+3)/2,1));
    vector<vector<bool>> vis((n+1),vector<bool>((n+3)/2,0));
    cout<<solve(0,(n+1)/2,p,dp,vis);
    return 0;
}
