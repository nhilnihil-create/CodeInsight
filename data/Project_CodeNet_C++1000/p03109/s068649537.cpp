#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  auto y = stoi(S.substr(0,4));
  auto m = stoi(S.substr(5,2));

  bool pred = true;
  if (y > 2019) {
    pred = false;
  } else if (y == 2019 && m > 4) {
    pred = false;
  }

  cout << (pred ? "Heisei" : "TBD") << endl;
  return 0;
}
