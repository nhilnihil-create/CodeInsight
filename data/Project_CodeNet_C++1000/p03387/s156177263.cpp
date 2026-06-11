#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int A, B, C, d, ans{};
  cin >> A >> B >> C;
  d = max({A, B, C}) * 3 - A - B - C;
  if (d%2==0) {
    ans = d/2;
  } else {
    ans = (d+3)/2;
  }
  cout << ans << endl;
}
