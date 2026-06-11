#include <iostream>
#include <set>

using namespace std;

int main() {
  int s;
  cin >> s;

  set<int> as;
  while (as.insert(s).second) s = s % 2 ? 3 * s + 1 : s >> 1;

  cout << as.size() + 1 << endl;

  return 0;
}
