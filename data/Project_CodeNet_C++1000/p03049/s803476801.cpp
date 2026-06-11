#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, ans{}, bh{}, at{}, ba{};
  cin >> N;
  vector<string> s(N);
  for (auto &x : s) {
    cin >> x;
    if (x[0] == 'B')
      if (x.back() == 'A') ++ba;
      else ++bh;
    else if (x.back() == 'A') ++at;
    for (int i = 0, n = x.size(); i < n - 1; ++i)
      if (x[i] == 'A' && x[i + 1] == 'B') ++ans, ++i;
  }

  ans += ba;
  if (bh + at) {
    ans += min(bh, at);
  } else if (ba) {
    --ans;
  }
  cout << ans << endl;
}
