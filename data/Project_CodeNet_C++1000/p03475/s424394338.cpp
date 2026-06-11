#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;

  int C[N], S[N], F[N];
  for (int i = 0; i < N - 1; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }

  // i 駅から N 駅までの最短時間をそれぞれ出力する
  for (int i = 0; i < N; i++) {
    int time = 0;
    for (int j = i; j < N - 1; j++) {
      if (time < S[j]) {
        // 始発まで待つ
        time = S[j];
      } else {
        // F[j] おきに発車する電車を待つ
        if (time % F[j] != 0) {
          time = time + F[j] - time % F[j];
        }  // else は待つ必要がない
      }
      time += C[j];
    }
    cout << time << endl;
  }
}