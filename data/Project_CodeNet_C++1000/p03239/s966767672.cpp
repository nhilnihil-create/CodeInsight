#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int c, t;
  int minc = 2000;

  for (int i = 0; i < N; ++i) {
    cin >> c >> t;
    if (t <= T) {
      minc = min(minc, c);
    }
  }
  if (minc == 2000) {
    cout << "TLE" << endl;
  } else {
    cout << minc << endl;
  }

  return 0;
}
