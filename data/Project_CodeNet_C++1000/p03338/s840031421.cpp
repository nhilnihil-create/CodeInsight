#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  int vmax = 0;
  for (int i = 1; i < N; ++i) {
    set<char> s1, s2, s;
    for (int j = 0; j < i; ++j) {
      s1.insert(S[j]);
    }
    for (int j = i; j < N; ++j) {
      s2.insert(S[j]);
    }

    for (char x : s1) if (s2.count(x)) s.insert(x);
    int cnt = s.size();
    vmax = max(vmax, cnt);
  }
  cout << vmax << endl;
}
