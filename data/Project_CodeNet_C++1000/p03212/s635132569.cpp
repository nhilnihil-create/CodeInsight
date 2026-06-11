#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42


using ll = long long;

set <int> v;

void go(ll x, int mask) {
   if(x  >= 1e9) return;
   if(mask == 7) v.insert(x);
   for(auto t: {3, 5, 7}) {
      int mask_ = mask | (1 << ((t - 3) / 2));
      go(x * 10LL + t, mask_);
   }
}
void pre() {
   go(0LL, 0);
}


void solve() {
   int n;
   cin >> n;
   int ans = 0;
   for(auto t: v) {
      ans += t <= n;
   }
   cout << ans << endl;
} 

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   pre();
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
