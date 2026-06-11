#include <iostream>

using namespace std;

int main() {
  char c;
  while (cin >> c)
    cout << (c == '1' ? 9 : 1);
  cout << endl;
}