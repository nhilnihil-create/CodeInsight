#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string S, T;
  cin >> S >> T;
  vector<vector<int>> _s(30), _t(30);
  REP(i, S.size()) {
    _s[S[i] - 'a'].push_back(i);
    _t[T[i] - 'a'].push_back(i);
  }
  REP(i, 30) {
    char c;
    REP(j, _t[i].size()) {
      if (j == 0) {
        c = S[_t[i][0]];
        continue;
      }
      if (c != S[_t[i][j]]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  REP(i, 30) {
    char c;
    REP(j, _s[i].size()) {
      if (j == 0) {
        c = T[_s[i][0]];
        continue;
      }
      if (c != T[_s[i][j]]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}