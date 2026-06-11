#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> a(N);
  rep(i, N)
  {
    cin >> a[i];
  }

  int ans;
  if (N == 1)
    ans = abs(a[0] - W);
  else
    ans = max(abs(a[N - 1] - W), abs(a[N - 2] - a[N - 1]));
  cout << ans << endl;
  return 0;
}