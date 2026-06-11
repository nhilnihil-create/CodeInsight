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
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }
    s = s[s.size() - 1] + s.substr(0, s.size() - 1);
  }
  cout << "No" << endl;
  return 0;
}