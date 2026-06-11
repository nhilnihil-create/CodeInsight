#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  std::reverse(s2.begin(), s2.end());
  if (s1 == s2) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
