#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int N;  // 店舗数
  int M;  // 購入したい本数
  cin >> N >> M;
  // 各店舗の栄養ドリンクの値段
  // 各店舗の購入できる最大本数
  vector<P>   ab(N);
  rep(i, N) {
    cin >> ab[i].first >> ab[i].second;
  }


  // M本の栄養ドリンクを買うのに必要な最小の金額
  ll ans = 0;
  sort(ab.begin(), ab.end());
  int count = 0;
  int i = 0;
  while (count < M) {
    int num = min(M - count, ab[i].second);
    ans += (ll)num * ab[i].first;
    count += num;
    i++;
  }

  cout << ans << endl;

  return 0;
}