#include <iostream>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  S += S;
  cout << (S.find(T) != S.npos ? "Yes" : "No") << endl;

  return 0;
}
