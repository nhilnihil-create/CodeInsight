#include "bits/stdc++.h"
using ll = long long;
using namespace std;


bool isPalindromic(int x) {
   string s = to_string(x);
   string t = s;
   reverse(t.begin(), t.end());
   return s == t;
}

void solve() {
   int a, b;
   cin >> a >> b;
   int ans = 0;
   for(int i = a; i <= b; i++) {
      if(isPalindromic(i)) ans++;
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
