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
  int ns = s.size(), nt = t.size();
  for (int i = ns - nt; i >= 0; i--) {
    bool succ = true;
    for (int j = 0; j < nt; j++)
      if (s[i + j] != '?') succ &= (s[i + j] == t[j]);
    if (succ) {
      for (int j = 0; j < nt; j++) s[i + j] = t[j];
      for (int j = 0; j < ns; j++)
        if (s[j] == '?') s[j] = 'a';
      cout << s << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}