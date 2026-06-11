#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t X, Y;
  cin >> X >> Y;
  if (X % Y == 0) {
    cout << -1 << endl;
  } else {
    cout << X << endl;
  }
  return 0;
}
