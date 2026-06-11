#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> B(m);
  for (int i = 0; i < m; ++i) {
    cin >> B[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> A(m);
    int solve = c;
    int a;
    for (int j = 0; j < m; ++j) {
      cin >> a;
      solve += a * B[j];
    }
    if (solve > 0) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
