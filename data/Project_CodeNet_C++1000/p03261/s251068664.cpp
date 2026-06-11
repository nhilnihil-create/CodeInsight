#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  set<string> used;
  int N; cin >> N;

  string prev; cin >> prev;
  used.insert(prev);

  for (int i = 1;  i < N; ++i) {
    string S; cin >> S;
    if (used.count(S)) {
      cout << "No" << endl;
      return 0;
    } else if (prev.back() != S[0]) {
      cout << "No" << endl;
      return 0;
    }
    used.insert(S);
    prev = S;
  }
  cout << "Yes" << endl;
}
