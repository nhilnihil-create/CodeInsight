/*
  Reference:-
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
ll mod=1000000007;
const int N=2e5 + 5;

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>s;
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=2;i<n+1;i++){
        ll pre[n+1]={0};
        forn(i1,n)pre[i1+1]=(pre[i1]+dp[i-1][i1+1])%mod;
        for(int j=1;j<i+1;j++){
            if(s[i-2]=='<')dp[i][j]=(pre[j-1]);
            else{
                ll temp=pre[n]-pre[j-1];
                temp=(temp+mod)%mod;
                dp[i][j]=temp;
            }
        }
    }
    ll ans=0;
    //forn(i,n){forn(j,n)cout<<dp[i+1][j+1];cout<<endl;}
    forn(i,n)ans=(ans+dp[n][i+1])%mod;
    cout<<ans;

    return 0;
}
