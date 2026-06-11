#include "bits/stdc++.h"
using ll = long long;
using namespace std;


bool good(string t) {
   bool ok = true;
   for(auto &c: t) {
      bool found = false;
      for(auto &e: vector <int> ({'A', 'C', 'G', 'T'})) {
         if(c == e) found = true;
      }
      ok &= found;
   }
   return ok;
}

void solve() {
   string s;
   cin >> s;
   int n = s.length();
   int ans = 0;
   for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
         string t = s.substr(i, j - i + 1);
         if(good(t)) {
            ans = max(ans, j - i + 1);
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
