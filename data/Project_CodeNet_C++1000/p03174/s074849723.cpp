#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    int N=1<<n;
    vector<long long>dp(N);
    dp[0]=1;
    for(int i=0;i<N;i++){
        int x=0;
        for(int j=i;j>0;j/=2)if(j%2)x++;
        for(int j=0;j<n;j++)if(a[x][j] && (i&(1<<j))==0)dp[i|(1<<j)]+=dp[i]%mod;
    }
    cout<<dp[N-1]%mod<<endl;
    return 0;
}