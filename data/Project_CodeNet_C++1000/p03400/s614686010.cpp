#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n, d, x;
   cin >> n >> d >> x;
   vector <int> a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int ans = 0;
   for(int i = 0; i < n; i++) {
      if(a[i] == 1) ans += d;
      else 
         for(int j = 1; j <= d; j++) {
            if(j % a[i] == 1) ans++;
         }
   }
   ans += x;
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
