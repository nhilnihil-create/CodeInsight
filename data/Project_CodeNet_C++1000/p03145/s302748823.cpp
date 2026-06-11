#include <algorithm>
#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int v[3] = {};
  cin >> v[0];
  cin >> v[1];
  cin >> v[2];
  sort(v, v + 2);

  int ans = v[0] * v[1] / 2;
  cout << ans << endl;

  return 0;
}
