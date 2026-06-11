#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s >> s;
  cout << (count(begin(s), end(s), 'R') > count(begin(s), end(s), 'B') ? "Yes"
                                                                       : "No")
       << endl;
  return 0;
}
