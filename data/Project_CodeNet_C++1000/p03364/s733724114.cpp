#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  char S[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    bool sym = true;
    char T[N][N];
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        T[j][k] = S[(j+i)%N][k];
      }
    }
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (T[j][k] != T[k][j]) {
          sym = false;
        }
      }
    }

    if (sym) {
      ans += N;
    }
  }

  cout << ans << endl;
  return 0;
}