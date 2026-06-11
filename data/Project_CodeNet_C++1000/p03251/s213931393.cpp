#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int maxX = X;
  rep(i, N) {
    int x;
    cin >> x;
    maxX = max(maxX, x);
  }
  int minY = Y;
  rep(i, M) {
    int y;
    cin >> y;
    minY = min(minY, y);
  }
  if (maxX < minY) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
  return 0;
}