#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int mod=int(1e9)+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int h[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    ll dp[n+1];
    for(int i=1;i<=n;i++){
        dp[i]=mod;
    }
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=max(1,i-k);j<i;j++){
            dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
        }
    }
    cout<<dp[n]<<"\n";
}