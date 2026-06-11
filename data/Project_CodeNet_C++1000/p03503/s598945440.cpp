#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   int N;
   cin >> N;
   vector<vector<bool>> F(N, vector<bool>(10, false));

   rep(i, 0, N) {
     rep(j, 0, 10) {
       int b;
       cin >> b;
       if (b) F.at(i).at(j) = true;
     }
   }

   vector<vector<int>> P(N, vector<int>(11));

   rep(i, 0, N) {
     rep(j, 0, 11) {
       cin >> P.at(i).at(j);
     }
   }

   int ans = -1000000000;

   for (int i = 1; i < (1 << 10); i++) {
     int tmp = 0;
     rep(j, 0, N) {
       int cnt = 0;
       rep(k, 0, 10) {
         if (i & (1 << k) && F.at(j).at(k)) cnt++;
       }
       tmp += P.at(j).at(cnt);
     }
     ans = max(ans, tmp);
   }

   cout << ans << endl;
 }
