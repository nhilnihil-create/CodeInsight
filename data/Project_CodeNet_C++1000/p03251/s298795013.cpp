#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int x, y;
  int maxx = X, miny = Y;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    maxx = max(maxx, x);
  }
  for (int i = 0; i < m; ++i) {
    cin >> y;
    miny = min(miny, y);
  }
  if (maxx + 1 <= miny) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
  return 0;
}
