#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int X;
  cin >> X;
  int answer = 1;
  for (int b = 2; b <= X; ++b) {
    int bp = b * b;
    for (int p = 2;; ++p) {
      if (X < bp) break;
      answer = max(answer, bp);
      bp *= b;
    }
  }
  cout << answer << endl;
  return 0;
}