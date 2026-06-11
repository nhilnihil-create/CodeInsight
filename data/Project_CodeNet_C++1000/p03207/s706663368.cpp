#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, p;
  cin >> n;
  int m = 0;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    s += p;
    m = max(m, p);
  }
  s -= m / 2;
  cout << s << endl;
  return 0;
}
