#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m,mod=(long long)(1e9)+7;
long long dp[1001][1001];
int main(){
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
cin>>n>>m;
char ch;
for(unsigned long long i=0;i<n;i++){
    for(unsigned long long j=0;j<m;j++){
        cin>>ch;
        if(ch=='#') dp[i+1][j+1]=-1;
    }
}
for(unsigned long long i=1;i<=n;i++){
    for(unsigned long long j=1;j<=m;j++){
        if(i==1&&j==1) {
            dp[i][j]=1;
            continue;
        }
        if(dp[i][j]==-1) continue;
        unsigned long long fst=dp[i][j-1],snd=dp[i-1][j];
        if(fst==-1) fst=0;
        if(snd==-1) snd=0;
        dp[i][j]=(fst+snd)%mod;
    }
}
cout<<dp[n][m]<<'\n';
return 0;
}
