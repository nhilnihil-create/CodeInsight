#include <iostream>
#include <vector>
#include <set>

using namespace std;

int hoge(int n) {
  if (n % 2 == 0)
    return n / 2;
  else
    return 3 * n + 1;
}

int main() {
  int s;
  cin >> s;
  set<int> cont;
  cont.insert(s);
  int last = s;
  for (int i = 2;; ++i) {
    last = hoge(last);
    if (cont.find(last) == cont.end()) {
      cont.insert(last);
      continue;
    }
    cout << i << endl;
    break;
  }
}
