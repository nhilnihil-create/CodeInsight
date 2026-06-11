#include "bits/stdc++.h"
using ll = long long;
using namespace std;


int sod(int x) {
   int ans = 0;
   while(x) {
      ans += (x % 10);
      x /= 10;
   }
   return ans;
}


void solve() {
   int n, a, b;
   cin >> n >> a >> b;

   int ans = 0;
   for(int i = 0; i < n; i++) {
      if(sod(i + 1) >= a && sod(i + 1) <= b) {
         ans += i + 1;
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
