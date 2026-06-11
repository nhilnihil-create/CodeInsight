#include <iostream>
using namespace std;
int main() {
  bool ans = false;
  int N;
  cin >> N;
  for (int a = 0; a <= 25; ++a) {
    for (int b = 0; b <= 15; ++b) {
        int total = 4*a + 7*b; // 合計金額
        if (total == N) ans = true; // 合計金額が X に一致したら答えをインクリメント
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}