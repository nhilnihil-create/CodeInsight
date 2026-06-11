#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin>>n>>k;
 
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<vector<int>> dp(2, vector<int>(k+1));
 
    int MOD=1e9+7;
 
    for(int j=0;j<=min(k, A[0]);j++){
        dp[0][j]=1;
    }
 
    for(int i=1;i<n;i++){
        int current=i%2;
        int last=!current;
        dp[current][0]=1;
        long long temp=1;
        for(int j=1;j<=A[i];j++){
            temp=(temp+(long long)dp[last][j])%(long long)MOD;
            dp[current][j]=temp;
        }
 
        for(int j=A[i]+1; j<=k; j++){
            if(j-A[i]-1>=0){
                temp=(temp-(long long)dp[last][j-A[i]-1]+MOD)%(long long)MOD;
            }
            temp=(temp+(long long)dp[last][j])%(long long)MOD;
            dp[current][j]=temp;
            
        }
    }
 
    int current=(n-1)%2;
    cout<<dp[current][k]<<endl;
}
