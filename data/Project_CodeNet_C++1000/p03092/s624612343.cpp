#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

struct TFenwickTree {
  vector<int> t;
  int n;
  
  void init(int nn)
  {
    n = nn;
    t.assign (n, 0);
  }
  
  int sum(int r)
  {
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
      result += t[r];
    return result;
  }
  
  void inc(int i, int delta)
  {
    for (; i < n; i = (i | (i+1)))
      t[i] += delta;
  }
  
  int sum (int l, int r)
  {
    if (l > r) return 0;
    return sum(r) - sum(l-1);
  }
};

typedef long long ll;

const int maxn = 5000;

ll cnt[maxn][maxn];
ll ans[maxn][maxn];

ll Solve(int k, int n, int a, int b, const vector<int>& pos) {
  if (k <= 0 || n == 0) return 0;
  ll& res = ans[k][n];
  if (res != -1) return res;

  if (pos[n] > k) {
    res = Solve(k, n - 1, a, b, pos);
    return res;
  }

  res = min(a + Solve(k, n - 1, a, b, pos), cnt[k][n] * b + Solve(pos[n] - 1, n, a, b, pos));
  return res;
}

int main()
{
  int n;
  ll a, b;
  cin >> n >> a >> b;
  vector<int> p(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }

  for (int k = 0; k < n; ++k) {
    TFenwickTree tree;
    tree.init(k + 1);
    for (int r = 0; r < n; ++r) {
      if (pos[r] > k) continue;
      cnt[k][r] = tree.sum(pos[r], k);
      tree.inc(pos[r], 1);
    }
  }


  memset(ans, -1, sizeof(ans));

  cout << Solve(n - 1, n - 1, a, b, pos) << endl;

  return 0;
}
