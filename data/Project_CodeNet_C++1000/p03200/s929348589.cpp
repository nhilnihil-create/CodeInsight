#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin >> s;
   vector<int> w;
   bool we = 0;
   for (int i = 0; i < (int)(s.length()); i++) {
      if (s[i] == 'W') {
         w.emplace_back(i);
         we = 1;
      }
   }
   if (we == 0) {
      cout << 0 << '\n';
      return 0;
   }
   long long ans = w[0];
   for (int i = 1; i < (int) w.size(); i++) {
      ans += w[i] - i;
   }
   cout << ans << '\n';
   return 0;
}