#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(m, 0);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      ++vec[a-1];
    }
  }

  int ans = 0;
  for (auto &v : vec)
    ans += v == n;

  cout << ans << endl;
}
