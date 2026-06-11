#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }

  bool is_ok = true;
  rep(i, N - 1)
  {
    if (A[i + 1] < A[i])
      continue;

    if (A[i + 1] == A[i] || A[i + 1] == A[i] + 1)
      continue;

    is_ok = false;
  }

  if (A[0] != 0)
    is_ok = false;

  if (!is_ok)
  {
    cout << -1 << endl;
    return 0;
  }

  long long ans = 0;
  rep(i, N - 1)
  {
    if (A[i] + 1 == A[i + 1])
      ans++;
    else
      ans += A[i + 1];
  }

  cout << ans << endl;
  return 0;
}