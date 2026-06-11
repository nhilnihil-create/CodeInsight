#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int s; cin >> s;
  set<int> used;
  used.insert(s);
  for (int i = 1;; ++i) {
    int ns = (s % 2 == 0) ? s/2 : 3*s+1;
    if (used.count(ns)) {
      cout << i + 1 << endl;
      return 0;
    }
    s = ns;
    used.insert(s);
  }
}
