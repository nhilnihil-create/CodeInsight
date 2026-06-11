#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> bs(m);
  for (auto &v : bs)
    cin >> v;

  int ans = 0;
  while (n--) {
    int vsum = c;
    for (int i = 0; i < m; ++i) {
      int tmp;
      cin >> tmp;
      vsum += bs[i] * tmp;
    }
    ans += 0 < vsum;
  }

  cout << ans << endl;
}