#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> x(N);

  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  long long ans = 10000000000;

  // 左端からKのレンジ分、繰り返す l がレンジの左端、r が右端
  for (int l = 0; l < N - K + 1; l++) {
    int r = l + K - 1;

    long long left = x[l];
    long long right = x[r];

    // 左に行った場合の時間と右に行った時間の小さい方を採用する
    long long goToLeftTime = abs(left) + abs(right - left);
    long long goToRightTime = abs(right) + abs(left - right);

    ans = min(ans, min(goToLeftTime, goToRightTime));
  }
  cout << ans << endl;
}