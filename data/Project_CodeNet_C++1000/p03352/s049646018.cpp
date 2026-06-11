#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T power(T x, int n) {
  T ans{1};
  while (n) {
    if (n % 2) ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}

void solve(int X) {
  int s = sqrt(X)+1;
  int x,ma{1};
  for(int i = 2; i < s; ++i) {
    x = 0;
    for (int j=2; x <= X; ++j) {
      ma = max(x,ma);
      x = power(i,j);
    }
  }
  cout << ma << endl;
}

int main() {
  int X;
  cin >> X;
  solve(X);
  return 0;
}
