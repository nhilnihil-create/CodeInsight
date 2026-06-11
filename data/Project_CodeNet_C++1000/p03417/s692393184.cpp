#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  long long h, w;
  cin >> h >> w;
  if (h == 1 && w == 1) {
    cout << 1 << endl;
  } else if (h == 1) {
    cout << max(w - 2, 0LL) << endl;
  } else if (w == 1) {
    cout << max(h - 2, 0LL) << endl;
  } else {
    cout << max((h - 2) * (w - 2), 0LL) << endl;
  }
  return 0;
}