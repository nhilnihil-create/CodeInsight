#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<set<int>> G(4);
  for (int i = 0; i < 3; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G.at(a).insert(b);
    G.at(b).insert(a);
  }
  vector<int> v = { 0, 1, 2, 3 };
  do {
    bool can = true;
    for (int i = 0; i < 3; i++) {
      if (!G.at(v.at(i)).count(v.at(i+1))) can = false;
    }
    if (can) {
      cout << "YES" << endl;
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << "NO" << endl;
}