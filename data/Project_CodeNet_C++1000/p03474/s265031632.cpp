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
  ll A, B;
  string s;
  cin >> A >> B >> s;
  if (s.length() != (A + B + 1)) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (i < A && !('0' <= s[i] && s[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
    if (i == A && s[i] != '-') {
      cout << "No" << endl;
      return 0;
    }
    if (A < i && !('0' <= s[i] && s[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}