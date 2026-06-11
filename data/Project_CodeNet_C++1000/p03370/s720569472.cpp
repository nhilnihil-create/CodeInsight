#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N, X;
  cin >> N >> X;

  vector<int> m(N);
  rep(i, N) {
    cin >> m[i];
    X -= m[i];
  }

  std::sort(m.begin(), m.end());

  int sum = N + X / m[0];
  cout << sum << endl;

  return 0;
}
