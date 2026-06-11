#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int x; cin >> x;
   if (x == 1){
      cout << 1 << endl;
      return 0;
   }
   int ans = 0;
   for (int i = 1; i <= x; i++){
      int j = i*i;
      while(j<=x){
         ans = max(ans, j);
         if (j == 1)break;
         j *= i;
      }
   }
   cout << ans << endl;
}