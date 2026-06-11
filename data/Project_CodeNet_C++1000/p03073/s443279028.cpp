#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < s.size()-1; i++) {
    if (s[i] == s[i+1]) {
      if (s[i] == '0') {
        s[i+1] = '1';
      } else {
        s[i+1] = '0';
      }
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}