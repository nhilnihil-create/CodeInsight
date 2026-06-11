#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[100010],x[100010],y[100010];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    int tt = t[i] - t[i-1];
    int xx = abs(x[i] - x[i-1]);
    int yy = abs(y[i] - y[i-1]);
    if (tt < xx + yy) {
      f = 0;
      break;
    }
    tt -= xx + yy;
    if (tt % 2 != 0) {
      f = 0;
      break;
    }
  }
  cout << (f?"Yes":"No") << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/