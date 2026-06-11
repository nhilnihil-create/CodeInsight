#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, X;
  cin >> N >> X;
  int min_m = 1000;
  rep(i, N) {
    int m;
    cin >> m;
    min_m = min(min_m, m);
    X -= m;
  }
  int answer = N + (X / min_m);
  cout << answer << endl;
  return 0;
}