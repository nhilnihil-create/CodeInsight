#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
   string a,b;
   cin >>a >>b;
   
   int n = (int)a.length();
   int m = (int)b.length();
   
   int dp[n+1][m+1];
   memset(dp, 0, sizeof(dp));
   
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           if(a[i-1]==b[j-1]){
               dp[i][j] = 1+dp[i-1][j-1];
           }
           else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
   }
   
   string s("");
   
   int i=n,j=m;
   
   while(i>0 && j>0){
       if(a[i-1]==b[j-1]){
           s.pb(a[i-1]);
           i--;   j--;
       }
       else if(dp[i-1][j] > dp[i][j-1]){
           i--;
       }
       else{
           j--;
       }
   }
   reverse(s.begin(), s.end()); 
       
   cout<<s;
    
    return 0;
}