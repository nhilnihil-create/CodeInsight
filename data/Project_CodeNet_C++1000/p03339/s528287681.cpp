

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<int> E(N), W(N);

  for (int i = 1; i < N; i++) {
    // i番がリーダーとしたときの方向転換が必要な人数の累積和
    W.at(i) = W.at(i - 1);
    E.at(N - 1 - i) = E.at(N - i);

    // 隣がリーダーからメンバーに戻ったときの増分
    if (s.at(i - 1) == 'W') {
      W.at(i)++;
    }
    if (s.at(N - i) == 'E') {
      E.at(N - 1 - i)++;
    }
  }
  //   cout << s << endl;

  //   for (int i = 0; i < N; i++) {
  //     cout << W.at(i);
  //   }
  //   cout << endl;
  //   for (int i = 0; i < N; i++) {
  //     cout << E.at(i);
  //   }
  //   cout << endl;

  int res = N;
  for (int i = 0; i < N; i++) {
    int c = W.at(i) + E.at(i);
    res = min(res, c);
  }
  cout << res << endl;
}