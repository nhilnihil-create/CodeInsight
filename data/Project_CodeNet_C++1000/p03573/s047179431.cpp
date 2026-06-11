#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int A, B, C;
  cin >> A >> B >> C;
  if (A == B) {
    cout << C << "\n";
  } else if (A == C) {
    cout << B << "\n";
  } else {
    cout << A << "\n";
  }
  return 0;
}
