#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 300;
double ans[N][N][N];
bool done[N][N][N];

double solve(int f1, int f2, int f3, int tot) {
  if (done[f1][f2][f3]) return ans[f1][f2][f3];
  const int n = f1 + f2 + f3;
  double res = 0;
  if (f1 > 0) {
    res += f1 * solve(f1 - 1, f2, f3, tot);
  }
  if (f2 > 0) {
    res += f2 * solve(f1 + 1, f2 - 1, f3, tot);
  }
  if (f3 > 0) {
    res += f3 * solve(f1, f2 + 1, f3 - 1, tot);
  }
  res = (res + tot)/n;

  done[f1][f2][f3] = true;
  ans[f1][f2][f3] = res;
  return res;
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  VI f(4);
  for (int a; cin >> a; f[a]++);
  done[0][0][0] = true;
  cout << fixed << setprecision(10) << solve(f[1], f[2], f[3], n) << endl;

  return 0;
}
