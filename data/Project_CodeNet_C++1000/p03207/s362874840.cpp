#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力部(N)
  int N;
  cin >> N;

  // 入力部(p1, p2, ... pN)
  vector<int> p(N);
  for(int i = 0; i < N; i++) {
    cin >> p.at(i);
  }

  // sum は 購入する品物の合計金額。
  // highest は 購入する品物の中で最高価格の景品の価格。
  int sum = 0, highest = 0;

  for(int i = 0; i < N; i++) {
    // sum に 価格の値段を加算。
    sum += p.at(i);

    // highest の最高価格を更新していく。
    highest = max(p.at(i), highest);
  }

  cout << sum - highest/2 << endl;
}
