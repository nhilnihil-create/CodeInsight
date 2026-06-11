#include<bits/stdc++.h>
using namespace std;
using ldb = long double;

int n;
ldb arr[3000];
ldb dp[3000][3000];

ldb solve(int x, int nn){
    if(x == 0) return 1.00;
    if(nn == -1) return 0.0;
    
    if(dp[x][nn] != -1) return dp[x][nn];
    
    ldb answer = arr[nn]*solve(x-1, nn-1) + (1.00-arr[nn])*solve(x, nn-1);
    
    return dp[x][nn] = (ldb)answer;
}

int main(){
    cin >>n;
    
    for(int i=0;i<n;i++) 
        cin >>arr[i];
        
    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j] = -1;
        }
    }
    
    cout<<fixed<<setprecision(12)<<(ldb)solve((n+1)/2, n-1);
    
    return 0;
}