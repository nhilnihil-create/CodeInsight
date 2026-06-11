#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s <= "2019/04/30") {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
  return 0;
}
