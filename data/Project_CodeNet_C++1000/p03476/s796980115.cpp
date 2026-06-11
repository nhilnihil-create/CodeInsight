#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

bool IsPrime(int num)  //素数判定
{
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  vector<ll> s(100005 + 1, 0), a(100005);
  for (int i = 1; i < 100005; i += 2) {
    if (IsPrime(i) && IsPrime((i + 1) / 2)) a[i]++;
  }
  rep(i, 100005) s[i + 1] = s[i] + a[i + 1];
  ll q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
  return 0;
}
