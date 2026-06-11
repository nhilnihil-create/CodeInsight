#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  long long N, K;
  cin >> N >> K;

  long long ans = 0;
  FOR(b, K + 1, N)
  {
    ans += N / b * (b - K) + max(N % b - K + 1, (long long)0);
  }
  if(K == 0)
    ans -= N;
  cout << ans << endl;
  return 0;
}