#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  long long K;
  cin >> N >> K;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> count(40);

  // A[0]からA[N-1]までの各桁の1の数を集計
  for (int i = 0; i < N; i++) {
    for (int j = 40; 0 <= j; j--) {
      if (A[i] >> j & 1) {
        count[j]++;
      }
    }
  }

  long long X = 0;

  // 10^12、およそ40桁を調べてXを求める
  for (int i = 40; 0 <= i; i--) {

    // XはKを超えたらダメ
    if (X + (1LL << i) > K) {
      continue;
    }
    
    // 桁の1の数が0の数より少ない場合は、
    // Xのその桁は1にする
    if (count[i] < N - count[i]) {
      X += (1LL << i);
    }

  }

  long long answer = 0;

  // 答えを求める
  for (int i = 0; i < N; i++) {
    answer += X ^ A[i];
  }

  cout << answer << endl;

  return 0;

}