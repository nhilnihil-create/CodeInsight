#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define repi(i, a, b) for (int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
using pii = pair<i32, i32>;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf64 = vector<f64>;
using vf80 = vector<f80>;
using vstr = vector<string>;
using vpii = vector<pii>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf64 = vector<vf64>;
using vvf80 = vector<vf80>;

template<typename T, typename S> bool amax(T &x, S y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T, typename S> bool amin(T &x, S y) { if (y < x) { x = y; return 1; } return 0; }

char board[110][110];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cerr << fixed << setprecision(16);
  int A, B;
  cin >> A >> B;
  vector<string> board(100);
  rep(i, 100) {
    if (i < 50) {
      board[i] = string(100, '#');
    } else {
      board[i] = string(100, '.');
    }
  }
  rep(i, A - 1) {
    int y = ((i * 2) / 100) * 2;
    int x = (i * 2) % 100;
    board[y][x] = '.';
  }
  rep(i, B - 1) {
    int y = 99 - ((i * 2) / 100) * 2;
    int x = (i * 2) % 100;
    board[y][x] = '#';
  }
  cout << 100 << " " << 100 << endl;
  rep(i, 100) {
    cout << board[i] << endl;
  }
  return 0;
}