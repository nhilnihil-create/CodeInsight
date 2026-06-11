#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  int n = static_cast<int>(str.size());
  bool flag = str == "keyence";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      string tmp = str.substr(0, i) + str.substr(j+1, n-j-1);
      if (tmp == "keyence")
        flag = true;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}
