#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }

  long long ANS = - (1LL << 40);
  for (int i = 1; i < (1 << 10); i++) {
    long long ans = 0;
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      for (int k = 0; k < 10; k++) {
        if (F[j][k] && ((i >> k) & 1)) {
          cnt ++;
        }
      }
      ans += P[j][cnt];
    }
    ANS = max(ANS, ans);
  }
  cout << ANS << endl;
}
