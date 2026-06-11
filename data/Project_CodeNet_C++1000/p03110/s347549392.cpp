#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n;
  double x;
  string u;
  double y = 0.0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> u;
    if (u == "JPY") {
      y += x;
    } else {
      y += x * 380000;
    }
  }
  cout << y << endl;
  return 0;
}
