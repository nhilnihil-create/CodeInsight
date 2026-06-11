#include <bits/stdc++.h>
using namespace std;
int mod =1e9+7;

int main(){
int n,k;
cin>>n>>k;
vector<int>A(n+1);
for(int i=1;i<=n;++i)
    cin >>A[i];
int dp[n+1][k+1];
dp[0][0]=1;
for(int i=1;i<=k;++i)
    dp[0][i]=0;
for(int i=1;i<=n;++i){

    vector<int>sum(k+1);
    sum[0]=dp[i-1][0];
     for(int j=1;j<=k;++j)
        sum[j]=(sum[j-1]+dp[i-1][j])%mod;
     for(int j=0;j<=k;++j){
        if(j<=A[i])
            dp[i][j]=sum[j];
        else{
            int l = j-A[i]-1;
            dp[i][j]=(sum[j]-sum[l]+mod)%mod;
        }
     }
     sum.clear();
}
cout <<dp[n][k]<<endl;

return 0;

}

