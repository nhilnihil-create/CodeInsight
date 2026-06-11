#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  string S;
  cin >> S;

  // 添え字0をリーダーにした場合の向きの変わる人数は
  // Eの人数を数える
  int right = 0;
  for (int i = 1; i < N; ++i) {
    if (S[i] == 'E') {
      right++;
    }
  }

  int ans = right;
  int left = 0;
  // 他がリーダーだった時
  for (int i = 1; i < N; ++i) {
    if (S[i - 1] == 'W') {
      left++;
    }

    if (S[i] == 'E') {
      right--;
    }
    ans = min(ans, left + right);
  }

  cout << ans << endl;
  
  return 0;
}