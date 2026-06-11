#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,K;
    cin>>n>>K;
    int k[40];
    for(int i=39;i>=0;i--){
        if(K%2)k[i]=1;
        else k[i]=0;
        K/=2;
    }
    long long sum=0;
    long long a[n];
    long long one[40]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        for(int j=0;j<40;j++){
            if(a[i]%2)one[j]++;
            a[i]/=2;
        }
    }
    long long w=1,v[40];
    for(int i=0;i<40;i++){
        v[i]=max(0ll,n-one[i]*2)*w;
        w*=2;
    }
    vector<vector<long long>>dp(41,vector<long long>(2,-1000000000000000000));
    dp[0][1]=0;
    for(int i=0;i<40;i++){
        dp[i+1][0]=dp[i][0]+v[39-i];
        if(k[i]){
            dp[i+1][1]=dp[i][1]+v[39-i];
            dp[i+1][0]=max(dp[i+1][0],dp[i][1]);
        }
        else dp[i+1][1]=dp[i][1];
    }
    cout<<max(dp[40][0],dp[40][1])+sum<<endl;
    return 0;
}
