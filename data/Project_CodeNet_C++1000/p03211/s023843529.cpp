#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   string s;
   cin >> s;
   int diff = INT_MAX;
   for(int i = 0; i + 2 < s.length(); i++) {
      diff = min(diff, abs(753 - stoi(s.substr(i, 3))));
   }
   cout << diff << endl;
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
