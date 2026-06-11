#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  string target = "keyence";
  int index = 0;
  if (s == target) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      string part = "";
      for (int k = 0; k < s.length(); k++) {
        if (i <= k && k <= j) continue;
        part += s[k];
      }
      if (part == target) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}