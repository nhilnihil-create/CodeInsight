#include <iostream>
using namespace std;

int dp[200020];

int p[200020];

int main(){
   int n;
   cin >> n;
   p[0] = -1;
   
   for(int i = 0 ; i < n ; i++){
    int j;
    cin >> j;
    p[j] = i;
   }
   
   int ans = 1;
   for(int i = 1 ; i <= n ; i++){
      dp[i] = 1;
      if( p[i-1] < p[i] ){
        dp[i] = dp[i-1] + 1;
        ans = max(ans, dp[i]);
      }
   }
   cout << n - ans << endl;
}