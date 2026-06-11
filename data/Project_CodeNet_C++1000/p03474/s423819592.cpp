#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;

  bool postal = true;
  rep(i, S.size()) {
    if (i == A) {
      if (S[i] != '-') {
        postal = false;
        break;
      }
    } else if (S[i] < '0' || S[i] > '9') {
      postal = false;
      break;
    }
  }

  if (postal) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
