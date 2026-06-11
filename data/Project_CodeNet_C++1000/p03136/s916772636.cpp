#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n;
  int l[10];
  cin >> n;
  int m = 0;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    m = max(m, l[i]);
    s += l[i];
  }
  s -= m;
  if (m < s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
