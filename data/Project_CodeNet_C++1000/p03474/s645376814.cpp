#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  if (S[A] != '-') {
    cout << "No" << endl;
    return 0;
  }
  rep(i, A + B + 1) {
    if (i != A && !isdigit(S[i])) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}