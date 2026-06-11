#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INF = 1LL << 60;

 int main() {
   int H, W;
   cin >> H >> W;
   vector<vector<int>> a(H, vector<int>(W));
   rep(y, 0, H) rep(x, 0, W) cin >> a.at(y).at(x);

   vector<tuple<int, int, int, int>> ans;
   rep(y, 0, H) rep(x, 0, W - 1) {
      if (a.at(y).at(x) % 2 == 1) {
          a.at(y).at(x)--;
          a.at(y).at(x + 1)++;
          ans.push_back(make_tuple(y, x, y, x + 1));
      }
   }
   rep(y, 0, H - 1) {
       if (a.at(y).at(W-1) % 2 == 1) {
           a.at(y).at(W - 1)--;
           a.at(y + 1).at(W - 1)++;
           ans.push_back(make_tuple(y, W - 1, y + 1, W - 1));
       }
   }
   cout << ans.size() << endl;
   for (auto t : ans) {
      int a, b, c, d;
      tie(a, b, c, d) = t;
      cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
   }
 }
