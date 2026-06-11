#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  long long N, M;
  cin >> N >> M;
  long long ans;
  if (N == 1 && M == 1)
    ans = 1;
  else if (N == 1 && M != 1)
    ans = M - 2;
  else if (N != 1 && M == 1)
    ans = N - 2;
  else if (N != 1 && M != 1)
    ans = (N - 2) * (M - 2);

  cout << ans << endl;
  return 0;
}