#include <iostream>

using namespace std;

int main() {
  int N, H, W, A, B, ans{};
  cin >> N >> H >> W;
  while (cin >> A >> B) {
    if (H <= A && W <= B) ++ans;
  }
  cout << ans << endl;
  return 0;
}
