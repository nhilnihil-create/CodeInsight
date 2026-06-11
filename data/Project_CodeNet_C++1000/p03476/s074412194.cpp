#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

bool IsPrime(int num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;  // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  bool a[100005];
  int b[100005];
  REP(i, 100001) { a[i] = IsPrime(i); }
  FOR(i, 3, 100001) {
    b[i] = b[i - 1];
    if (i % 2 != 0 && a[i] && a[(i + 1) / 2]) b[i] += 1;
  }
  int q;
  cin >> q;
  int l[100005];
  int r[100005];
  REP(i, q) { cin >> l[i] >> r[i]; }
  REP(i, q) { cout << b[r[i]] - b[l[i] - 1] << endl; }
}