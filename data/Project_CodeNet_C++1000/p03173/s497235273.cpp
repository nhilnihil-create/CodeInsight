#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
ll dp1[400][400];
ll dp2[400][400];
const ll INF = 1ll<<60;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   rep(i,n){
      cin >> dp1[i][i];
   }
   for (int size = 1; size < n; size++){
      for (int left = 0; left < n-size; left++){
         int right = left+size;
         dp1[left][right] = dp1[left][left]+dp1[left+1][right];
      }
   }
   for (int size = 1; size < n; size++){
      for (int left = 0; left < n-size; left++){
         int right = left+size;
         dp2[left][right] = INF;
         for (int k = 0; left+k < right; k++){
            dp2[left][right] = min(dp2[left][right], dp2[left][left+k]+dp2[left+k+1][right]+dp1[left][right]);
         }
      }
   }
   cout << dp2[0][n-1] << endl;
}