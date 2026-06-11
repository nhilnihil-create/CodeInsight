#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;
    
    vector<int> dp(n);
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    dp[0] = 0;
    for(int i=1; i<n; i++){
        
        dp[i] = INT_MAX;
        for(int j=1; j<=k && j<=i; j++){
        int q = dp[i-j]+ abs(v[i]-v[i-j]);
        if(dp[i]>q) dp[i] = q;
        }
    }
    
    cout<<dp[n-1]<<endl;
    
    
}