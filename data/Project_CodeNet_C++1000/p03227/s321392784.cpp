#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef int64_t Int;
Int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  if (s.size() == 2) {
    dump(s);
  }
  else {
    reverse(s.begin(), s.end());
    dump(s);
  }
  return 0;
}
