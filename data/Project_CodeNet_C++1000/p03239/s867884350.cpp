#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, T, i, c, t, ans_c = 1005, ans_t = 0;
   cin >> N >> T;

   for (i = 0; i < N; i++) {
      cin >> c >> t;
      if (t <= T && c <= ans_c) {
         ans_c = c;
      }
   }
   if (ans_c == 1005) { 
      cout << "TLE" << endl;
      return 0;
   } 
   cout << ans_c << endl;

   return 0;
}
