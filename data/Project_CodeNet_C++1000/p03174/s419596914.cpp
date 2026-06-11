//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define INF 9223372036854777ll
#define pb push_back
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    int dp[(1<<n)]={};
    dp[0]=1;
    for(int i=0;i<(1<<n)-1;++i){
        int x=__builtin_popcount(i);
        for(int j=0;j<n;++j){
            if(a[x][j] && !(i & (1<<j))){
                int m=i ^ (1<<j);
                dp[m]+=dp[i];
                dp[m]%=mod;
            }
        }
    }
    
    cout<<dp[(1<<n)-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
