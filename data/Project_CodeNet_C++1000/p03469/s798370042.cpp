#include <iostream>
using namespace std;
int main() {
  string S;
  cin >> S;
  if (S.substr(3, 1) == "7") S.replace(3, 1, "8");
  cout << S << endl;
}