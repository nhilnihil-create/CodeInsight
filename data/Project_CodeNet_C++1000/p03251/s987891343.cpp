#include <iostream>

using namespace std;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int mxx = X, mny = Y;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mxx = max(mxx, x);
  }
  for (int j = 0; j < m; ++j) {
    int y;
    cin >> y;
    mny = min(mny, y);
  }
  puts(mxx<mny?"No War":"War");
}
