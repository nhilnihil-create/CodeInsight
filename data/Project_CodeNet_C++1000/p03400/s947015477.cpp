#include <iostream>

using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int a, ans{X + N};
  for (; N--;) {
    cin >> a;
    ans += (D - 1) / a;
  }
  cout << ans << endl;
  return 0;
}
