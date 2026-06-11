#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;;

int main() {
  int n, m;  cin >> n >> m;
  vector<int> r(n, INF);
  for(int i=0; i<m; i++){
    int a, b;  cin >> a >> b;
    --a; --b;  // 0 <= i < n  の区間に正規化
    r[a] = min(r[a], b);  // aからスタートする点の中で一番先にゴールする点を格納
  }

  int x = INF, ans = 0;
  for(int i=0; i<n; i++){
    if (x == i) x = INF, ans++;  // 下で格納した点が来て、ゴールになった場合リセットしてまた一番近いゴールを格納し始める
    x = min(x, r[i]);  // iからスタートする点があれば、その中で一番先にゴールするときの点を格納してる
  }
  cout << ans << endl;
  return 0;
}
