#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string str;
  cin >> str;
  int k;
  cin >> k;

  stringstream ss(str);
  int cnt = 0;
  char c;
  while (ss >> c) {
    if (c != '1')
      break;
    ++cnt;
  }

  if (k <= cnt)
    cout << 1 << endl;
  else
    cout << c << endl;
}
