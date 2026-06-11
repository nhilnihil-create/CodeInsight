#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  int N;
  cin >> N;

  if (N == 1) {
    cout << "Hello World" << endl;
  } else {
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }

  return 0;
}
