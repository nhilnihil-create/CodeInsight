#include <algorithm>
#include <iostream>

int sd(int x) {
  int ret{};
  while(x) {
    ret += x %10;
    x /= 10;
  }
  return ret;
}

using namespace std;
int main() {
  int N, mi;
  cin >> N;
  mi = N;
  for (auto i = 1; i <=N/2; ++i) {
    mi = min(mi,sd(i)+sd(N-i));
  }
  cout << mi << endl;
  return 0;
}
