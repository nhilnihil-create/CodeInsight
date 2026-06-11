#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

const int N = 10;

int a[N], b[N], d[N];
int n, ans = 2e9;

void check() {
  vector<int> c(4);
  int cal = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] && c[b[i]]) cal += 10;
    c[b[i]] += a[i];
  }
  for (int i = 1; i <= 3; i++) {
    if (c[i] == 0) return;
    cal += abs(c[i] - d[i]);
  }
  ans = min(ans, cal);
}

void brute(int i) {
  for (int j = 0; j <= 3; j++) {
    b[i] = j;
    if (i == n) check();
    else brute(i + 1);
  }
}

void MAIN() {
  cin >> n;
  cin >> d[1] >> d[2] >> d[3];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  brute(1);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
