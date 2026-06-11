#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5 << 28, MOD = 1e9 + 7;

int A, B;

void input() { cin >> A >> B; }
int ms[100][100] = {};
void solve() {
  rep(i, 0, 99) {
    rep(j, 0, 99) {
      if (i <= 49) {
        ms[i][j] = 0;
      } else {
        ms[i][j] = 1;
      }
    }
  }

  int cnta = 1;
  int cntb = 1;
  for (int i = 1; i < 49; i += 2) {
    for (int j = 1; j < 99; j += 2) {
      if (cnta < A) {
        ms[i][j] = 1;
        cnta++;
      }
    }
  }
  for (int i = 51; i < 99; i += 2) {
    for (int j = 1; j < 99; j += 2) {
      if (cntb < B) {
        ms[i][j] = 0;
        cntb++;
      }
    }
  }

  cout << "100 100" << endl;
  rep(i, 0, 99) {
    rep(j, 0, 99) { cout << (ms[i][j] == 0 ? "#" : "."); }
    cout << endl;
  }
}
signed main() {
  input();
  solve();
  return 0;
}