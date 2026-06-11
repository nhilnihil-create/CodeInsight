#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > 8 || b > 8) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
  return 0;
}
