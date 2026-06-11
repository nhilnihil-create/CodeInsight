#include <iostream>
#include <string>

using namespace std;

int main() {
  string n;
  cin >> n;
  for (char& c : n) {
    if (c == '1') {
      c = '9';
    } else {
      c = '1';
    }
  }
  cout << n << endl;
  
  return 0;
}
