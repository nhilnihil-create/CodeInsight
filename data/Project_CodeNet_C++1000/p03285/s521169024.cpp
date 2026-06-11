#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 0; i * 4 <= n; ++i) {
    int rest = n - i * 4;
    if (rest % 7 == 0) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
