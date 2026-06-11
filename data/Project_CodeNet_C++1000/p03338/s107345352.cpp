#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42

using ll = long long;

void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;

   map <char, int> m, c;
   for(int i = 0; i < n; i++) {
      m[s[i]]++;
   }

   int ans = 0;
   for(int i = 0; i < n; i++) {
      c[s[i]]++;
      int t_ans = 0;
      for(auto ch: c) {
         if(ch.second < m[ch.first])
            t_ans++;
      }
      ans = max(ans, t_ans);
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
