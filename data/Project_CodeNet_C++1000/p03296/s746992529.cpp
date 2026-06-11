#include <iostream>

using namespace std;

int main() {
  int N, a, b,ans{};
  cin >> N;
  while (cin >> a) {
    if (a==b) ++ans, a=0;
    b = a;
  }
  cout << ans << endl;
  return 0;
}
