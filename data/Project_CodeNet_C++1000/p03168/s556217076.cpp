#include <bits/stdc++.h>
using namespace std;
void coins( int n,double a[]){
   double dp[n+1][n+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
           dp[i][j]=0;
       }
   }
   dp[1][0]=1.0-a[1];
   //cout<<dp[1][0];
   for(int i=2;i<=n;i++){
       dp[i][0]=dp[i-1][0]*(1.0-a[i]);
   }
   dp[1][1]=a[1];
   for(int i=2;i<=n;i++){
       dp[i][i]=dp[i-1][i-1]*a[i];
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<i;j++){
           dp[i][j]=dp[i-1][j]*(1.0-a[i])+dp[i-1][j-1]*a[i];
       }
   }
   double ans=0;
   for(int i=n/2+1;i<=n;i++){
       ans+=dp[n][i];

   }
   //cout<<ans;
    cout << fixed << setprecision(10) << ans;
    //return 0;


}
int main() {
   int n;
   cin>>n;
  double a[n+1];
  // int k=1;
   for(int i=1;i<=n;i++){
       cin>>a[i];
     // k=k*a[i];
   }
  coins(n,a);
}
