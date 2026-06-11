#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42

using ll = long long;

void solve() {
   int n;
   cin >> n;
   vector <int> a(n);
   int g = 0;
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      g = __gcd(g, a[i]);
   }
   cout << g << endl;
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
