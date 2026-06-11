#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;

void rec(int& ans, int n, int G, vector<int>& comp, vector<int>& p, vector<int>& c) {
  // ベースケース
  if (n == comp.size()) {
    int sum = 0;
    int num = 0;
    rep(i, comp.size()) {
      if (comp[i]) {
        sum += p[i] * (i + 1) * 100 + c[i];
        num += p[i];
      }
    }

    if (sum < G) {
      for (int i = comp.size() - 1; i >= 0; --i) {
        if (comp[i] == 0) {
          int point = (i + 1) * 100;
          int a = (G - sum + point - 1) / (point); // 足りない問題数
          if (a < p[i]) {
            sum += a * point;
            num += a;
            break;
          } else {
            // 他にもコンプが必要というシチュエーションは、再帰によって網羅しているはずなので処理を打ち切る
            return;
          }
        }
      }
    }

    ans = min(ans, num);
    
    return;
  }

  // 再帰ステップ
  comp[n] = 0;
  rec(ans, n + 1, G, comp, p, c);
  comp[n] = 1;
  rec(ans, n + 1, G, comp, p, c);
}


int main(void) {
  int D, G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);
  rep(i, D) {
    cin >> p[i] >> c[i];
  }

  int ans = 10 * 100 + 50;
  vector<int> comp(D, 0);
  rec(ans, 0, G, comp, p, c);

  cout << ans << endl;
  
  return 0;
}