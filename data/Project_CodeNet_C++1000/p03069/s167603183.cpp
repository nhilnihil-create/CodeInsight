#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  // 最終状態は
  // 1. 全部黒 2.左から白が連続した後、すべて黒が連続する 3. 全部白
  // あるiに対して、左にいくつ黒があって、右にいくつ白があるかの配列を作ればO(n)で2.の最大は求められる
  vector<int> left_black(n);
  vector<int> right_white(n);

  int black = 0;
  REP(i, n) { left_black[i] = (s[i] == '#') ? ++black : black; }
  int white = 0;
  for (int i = n - 1; i >= 0; i--) {
    right_white[i] = (s[i] == '.') ? ++white : white;
  }
  /*
  REP(i, n) { cout << left_black[i] << " "; }
  cout << endl;
  REP(i, n) { cout << right_white[i] << " "; }
  */
  int middle_ans = INT_MAX;
  REP(i, n - 1) {
    middle_ans = min(middle_ans, left_black[i] + right_white[i + 1]);
  }
  int ans = min(middle_ans, min(black, white));
  cout << ans << endl;
}