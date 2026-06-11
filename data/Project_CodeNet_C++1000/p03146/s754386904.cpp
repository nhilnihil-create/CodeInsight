#include <iostream>
#include <set>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int s;
  set<int> a;
  cin >> s;
  int p;
  for (int i = 1; i < 1000000; ++i) {
    if (i == 1) {
      a.insert(s);
      p = s;
      continue;
    }
    if (p % 2 == 0) {
      s = p / 2;
    } else {
      s = p * 3 + 1;
    }
    if (a.find(s) != a.end()) {
      cout << i << endl;
      break;
    }
    a.insert(s);
    p = s;
  }

  return 0;
}
