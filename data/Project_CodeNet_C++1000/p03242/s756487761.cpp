#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string n;
  cin >> n;
  rep(0, n.size()) {
    if (n[i] == '1') {
      cout << '9';
    } else {
      cout << '1';
    }
  }
  cout << endl;
  return 0;
}
