/*
Created by Rishu Sahu @ covid 20-20
*/
/*
*****************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pai pair<int,int>
#define pal pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,a,b) for(int i=a;i<=b;i++)
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define vi vector<int>
#define vl vector<ll>
#define mpl map<ll,ll>
#define mpi map<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

double dp[sze][sze];

void solve(){
    int n;
    cin>>n;
    double head[n+1];
    double tail[n+1];
    rep(i,n) {
        cin>>head[i+1];
        tail[i+1]=1.0-head[i+1];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++){
        dp[i][0]=tail[i]*dp[i-1][0];
        for(int j=1;j<=i;j++){
            dp[i][j]=head[i]*dp[i-1][j-1]+tail[i]*dp[i-1][j];
        }
    }
    double ans=0;
    for(int i=n/2+1;i<=n;i++)
    ans+=dp[n][i];

    cout<<fixed<<setprecision(10)<<ans<<endl;

}

int main(){
    solve();
}
