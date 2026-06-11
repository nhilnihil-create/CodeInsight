#include <bits/stdc++.h>
using namespace std;
string s;
bool compare(pair<int,int> a, pair<int,int> b) {
  return s.substr(a.first,a.second) < s.substr(b.first,b.second);
}
int main() {
  int K;
  cin >> s >> K;
  set<string> X;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 1; j <= K && i+j <= s.length(); j++) {
      X.insert(s.substr(i,j));
    }
  }
  for (auto p : X) {
    if (!(--K)) {
      cout << p;
      return 0;
    }
  }
}