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
  int a[10005];
  int b[10005];

  cin >> n;
  REP(i, n) { cin >> a[i]; }
  REP(i, n) { cin >> b[i]; }

  ll a_cnt = 0;
  ll b_cnt = 0;
  REP(i, n) {
    if (a[i] < b[i]) {
      int cnt = (b[i] - a[i] + 1) / 2;
      a_cnt += cnt;
      a[i] += 2 * cnt;
    }
  }
  REP(i, n) {
    if (b[i] < a[i]) {
      int cnt = a[i] - b[i];
      b_cnt += cnt;
    }
  }

  if (b_cnt <= a_cnt) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}