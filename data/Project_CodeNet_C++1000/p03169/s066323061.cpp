#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double> v(n);
    int ones=0, twos=0, threes=0, max_ones, max_twos, max_threes;
    int i,j,k;
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++) {
        if(v[i]==1) ones++;
        else if(v[i]==2) twos++;
        else threes++;
    }
    max_ones = ones+twos+threes;
    max_twos = twos+threes;
    max_threes = threes;
    
    double dp[n+1][n+1][n+1]={0.0};
    
    for(k=0; k<=max_threes; k++){
        for(j=0; j<=max_twos-k; j++){
            for(i=0; i<=max_ones-j-k; i++){
                if(i+j+k==0) continue;
                else{
                    dp[i][j][k]=double(n)/(i+j+k);
                    if(i>0) dp[i][j][k] += (dp[i-1][j][k]*i)/(i+j+k);
                    if(j>0) dp[i][j][k] += (dp[i+1][j-1][k]*j)/(i+j+k);
                    if(k>0) dp[i][j][k] += (dp[i][j+1][k-1]*k)/(i+j+k);
                }
            }
        }
    }
    cout<<setprecision(20)<<dp[i-1][j-1][k-1]<<endl;
    return 0;
}
