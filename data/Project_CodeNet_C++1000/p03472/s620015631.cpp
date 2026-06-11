#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, H, a, MA{}, ans{};
  cin >> N >> H;
  vector<int> b(N);
  for (int i = 0; i != N; ++i) {
    cin >> a >> b[i];
    MA = max(MA, a);
  }
  sort(rbegin(b), rend(b));
  for (int i = 0; i != N; ++i) {
    if (H <= 0 || b[i] < MA) break;
    ++ans;
    H -= b[i];
  }
  if (H > 0) ans += (H-1) / MA + 1;
  cout << ans << endl;
}
