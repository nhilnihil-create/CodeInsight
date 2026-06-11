#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}
// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

typedef long long ll;

bool check(const vector<string>& board, int shift) {
  int n = board.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char cur = board[i][j];
      char rev = board[(j+n-shift)%n][(i+shift)%n];
      if (cur != rev) return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<string> board(n);
  for (string &s: board) {
    cin >> s;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (check(board, i)) {
      ans += n;
    }
  }
  cout << ans << endl;
}
