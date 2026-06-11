#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >>n;
    vector<int>dp(n,0);
    for(int i=1;i<=n;i++){
        for(int j=1;i*j<=n;j++){
            if(i*j%2==1)dp[i*j-1]++;
        }
    }
    
    cout <<count(dp.begin(),dp.end(),8);
}
