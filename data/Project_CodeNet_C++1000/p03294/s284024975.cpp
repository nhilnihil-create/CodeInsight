   #include "bits/stdc++.h"
   using ll = long long;
   using namespace std;

   void solve() {
      int n;
      cin >> n;
      ll ans = 0, x;
      for(int i = 0; i < n; i++) {
         cin >> x;
         ans += x - 1;
      }
      cout << ans << endl;
   }

   int main() {
      cin.tie(0);
      cin.sync_with_stdio(0);
      int testcase = 1;
      // cin >> testcase;
   
      for(int i = 0; i < testcase; i++) {
         solve();
      } 
      return 0;
   }
