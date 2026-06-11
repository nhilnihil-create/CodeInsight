#include<bits/stdc++.h>
using namespace std;
int sol(int n,int k,vector<int>v){
    vector<vector<int>>dp(n,vector<int>(k+1,-1000000000));
    dp[0][0]=v[0];
    if(n>1)dp[0][1]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k-1;j++){
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+v[i+1]);
            dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]);
        }
    }
    int m=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            m=max(m,dp[i][j]);
        }
    }
    return m;
}
int main(){
    int n,k;
    cin>>n>>k;
    int v[n];
    vector<int>vl(n);
    vector<int>vr;
    for(int i=0;i<n;i++){
        cin>>v[i];
        vl[i]=v[i];
    }
    if(n==1){
        cout<<max(v[0],0)<<endl;
        return 0;
    }
    int m=0;
    for(int i=n-1;i>0;i--){
        vl.pop_back();
        vr.push_back(v[i]);
        for(int j=0;j<=k;j++){
            m=max(m,sol(i,j,vl)+sol(n-i,k-j,vr));
        }
    }
    cout<<m<<endl;
    return 0;
}