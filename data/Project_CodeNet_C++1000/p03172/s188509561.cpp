#include<bits/stdc++.h>

using namespace std;

const long long MOD=7+1e9;
int main(){
    long long n, k;
    cin>>n>>k;

    vector<long long> A(n);
    for(long long &x:A){
        cin>>x;
    }
    vector<vector<long long>> dp(2, vector<long long>(k+1));
    for(int i=0;i<=A[0];i++){
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        int curr=(i%2);
        int last=(!curr);
        long long temp=0;
        for(int j=0;j<=k;j++){
            if(j-A[i]-1>=0){
                temp-=dp[last][j-A[i]-1];
                temp=(temp+MOD)%MOD;
            }
            temp+=(dp[last][j]);
            temp%=MOD;
            dp[curr][j]=temp;
        }
    }

    int last=(n-1)%2;
    cout<<dp[last][k]<<endl;
}