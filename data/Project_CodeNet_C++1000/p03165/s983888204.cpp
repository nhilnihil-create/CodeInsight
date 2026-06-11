

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {

    string s,t;
    cin >> s >> t;
   int n = s.size();
   int m = t.size();

   int dp[n+1][m+1];
   memset(dp, 0, sizeof(dp));


   for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
   }

   string ans;

   int i=n,j=m;

   while(i>0 && j>0){
       if(dp[i][j] == dp[i-1][j-1] + 1 && s[i-1] == t[j-1]){
        //cout << i << " " << j << endl;
        //cout << s[i-1] << " " << t[j-1] << endl << endl;

          ans.pb(s[i-1]);
          i--;
          j--;
       }
       else if (dp[i][j] == dp[i-1][j]){
          i--;
       }
       else {
          j--;
       }
   }
    reverse(ans.begin(),ans.end());

   cout << ans;

    return 0;
}
