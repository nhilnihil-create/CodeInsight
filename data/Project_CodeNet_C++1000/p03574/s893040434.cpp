#include "bits/stdc++.h"
using ll = long long;
using namespace std;


int sod(int x) {
   int ans = 0;
   while(x) {
      ans += (x % 10);
      x /= 10;
   }
   return ans;
}


void solve() {
   int n, m;
   cin >> n >> m;
   vector <vector <int>> ans(n, vector <int> (m));
   vector <string> s(n);
   for(int i = 0; i < n; i++) {
      cin >> s[i];
   }

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(s[i][j] == '#') continue;
         for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
               if(di == 0 && dj == 0) continue;
               int r = i + di;
               int c = j + dj;
               if(r >= 0 && r < n && c >= 0 && c < m) {
                  ans[i][j] += s[r][c] == '#';
               }
            }
         }
      }
   }

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(s[i][j] == '#') cout << s[i][j];
         else cout << ans[i][j];
      }
      cout << endl;
   }
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
