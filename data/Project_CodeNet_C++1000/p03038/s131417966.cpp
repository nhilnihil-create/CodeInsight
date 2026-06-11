#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
#define debug(...) 42


using ll = long long;

ll f(ll n, ll x) {
   return n / x;
}

void solve() {
   int n, m, x, y;
   cin >> n >> m;
   vector <int> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
   }
   sort(v.begin(), v.end());

   vector <pair <int, int> > cb(m);
   for(int i = 0; i < m; i++) {
      cin >> x >> y;
      cb[i] = {y, x};
   }
   sort(cb.rbegin(), cb.rend());

   debug(cb);
   int ptr = 0;
   for(int i = 0; i < m; i++) {
      int c = cb[i].first;
      int b = cb[i].second;
      debug(c, b, ptr);
      int ptr1 = ptr;
      for(int j = ptr; j < min(ptr + b, n); j++) {
         if(v[j] < c) {
            v[j] = c;
            ptr1 = j + 1;
         }
         else break;
      }
      ptr = ptr1;
   }
   debug(v);
   ll ans = accumulate(v.begin(), v.end(), 0LL);
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
