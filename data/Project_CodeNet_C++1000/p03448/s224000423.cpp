#include "bits/stdc++.h"
using ll = long long;
using namespace std;


void solve() {
   int a, b, c, x;
   int ans = 0;
   cin >> a >> b >> c >> x;
   for(int i = 0; i <= a; i++) {
      for(int j = 0; j <= b; j++) {
         for(int k = 0; k <= c; k++) {
            if(i * 500 + j * 100 + k * 50 == x) ans++;
         }
      }
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
