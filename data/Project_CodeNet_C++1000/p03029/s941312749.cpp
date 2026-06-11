#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;
int main() {
  int A,P;
  cin >> A >> P;
  cout << (A*3+P)/2 << endl;
  return 0;
}