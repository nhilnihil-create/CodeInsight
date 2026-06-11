#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// #include "debug.h"
#define debug(...) 42

const int mod = 1e9 + 7;

string get(string s, string t, int idx) {
   for(int i = idx; i < idx + t.length(); i++) {
      if(s[i] == '?') {
         s[i] = t[i - idx];
      } else if(s[i] == t[i -idx]) {
         continue;
      } else {
         return "";
      }
   }
   for(auto &c: s) {
      if(c == '?') {
         c = 'a';
      }
   }
   return s;
}

void solve() {
   string s, t;
   cin >> s >> t;
   string ans(51, 'z');

   int n = s.length();
   int m = t.length();
   
   for(int i = 0; i + m - 1 < n; i++) {
      string t_ans = get(s, t, i);
      if(!t_ans.empty()) {
         ans = min(ans, t_ans);
      }
   }

   debug(ans);
   if(ans == string(51, 'z')) 
      ans = "UNRESTORABLE";
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
