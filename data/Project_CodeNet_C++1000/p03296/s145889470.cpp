#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int last = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (last == x) {
      ans++;
      last = -1;
    } else {
      last = x;
    }
  }

  cout << ans << endl;
}
