#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int main() {
  int N;
  cin >> N;
  vector<vector<char>> S(N, vector<char>(N, '0'));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) { cin >> S[i][j]; }
  }
  uint32_t ans = 0;
  for (int x = 0; x < N; x++) {
    //「右にxずらし」で盤面が対称になるかどうかチェック
    bool flag = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int a = (i + x) % N;
        int b = (j - x + N) % N;
        if (S[i][j] != S[b][a]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) ans += N;
  }
  cout << ans << endl;
  return 0;
}
