#include <bits/stdc++.h>
using namespace std;
double a[3000];
double dp[3000][3000];


//dp[i][x] denotes the probality of getting atleast x heads in toss of first i coins.
double solve(int i, int heads){
        if(heads==0){
            return 1.0;
        }

        if(i==0){
            return 0.0;
        }
   
    if(dp[i][heads] + 0.95 >0){
        return dp[i][heads];
    }

   return dp[i][heads]=a[i]*solve(i-1, heads-1 ) + (1.0-a[i])*solve(i-1, heads);
}
int main() {
    int n; 
    cin>>n;
    memset(dp, -1, sizeof dp);
    n++;
    for(int i=1;i<n;++i){
   cin>>a[i];
    }
   n--;
  cout<<fixed<<setprecision(10)<<solve(n ,  (n+1)/2);
   return 0;
}
