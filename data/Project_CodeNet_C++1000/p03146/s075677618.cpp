#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int S;
  cin >> S;
  int prev = S;
  unordered_set<int> lookup;
  lookup.insert(S);
  for (int i = 2; i <= 1000000; ++i) {
    int a;
    if (prev % 2) {
      a = 3 * prev + 1;
    } else {
      a = prev / 2;
    }
    if (lookup.count(a)) {
      cout << i << endl;
      return 0;
    } else {
      lookup.insert(a);
    }
    prev = a;
  }
  return 0;
}