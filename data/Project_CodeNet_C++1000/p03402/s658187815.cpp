#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B; cin >> A >> B;

  cout << 100 << " " << 100 << "\n";

  vector<string> ans;
  int count;

  ans.assign(50, string(100, '#'));
  count = 0;
  for (int i = 0; i < 50; i++) {
    if (count < A - 1 && i % 2 == 0) {
      for (int j = 0; j < 100; j += 2) {
        ans[i][j] = '.';
        if (++count == A - 1) break;
      }
    }
    cout << ans[i] << "\n";
  }

  ans.assign(50, string(100, '.'));
  count = 0;
  for (int i = 0; i < 50; i++) {
    if (count < B - 1 && i % 2) {
      for (int j = 0; j < 100; j += 2) {
        ans[i][j] = '#';
        if (++count == B - 1) break;
      }
    }
    cout << ans[i] << "\n";
  }
}