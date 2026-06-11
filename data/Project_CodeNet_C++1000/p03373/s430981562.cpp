#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greater<int>()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

const int INF = 1001001001;
const int MOD = 1000000007;
const long long INFL = (1LL << 60);
const double EPS = 1e-9;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  pair<int, int> piz[] = {make_pair(A, X), make_pair(B, Y)};

  int res = 0;
  if (A + B > C * 2) {
    pair<int, int> maxp, minp;
    if (X >= Y)
      maxp = piz[0], minp = piz[1];
    else
      maxp = piz[1], minp = piz[0];
    int diff = maxp.second - minp.second;
    res = C * minp.second * 2 + diff * maxp.first;
    int allC = C * maxp.second * 2;
    if (res > allC) res = allC;
  } else {
    res = A * X + B * Y;
  }

  cout << res << endl;
}