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
  int N, K;
  cin >> N >> K;
  vector<long long> a(N + 1);
  rep(i, N)
  {
    cin >> a[i + 1];
  }
  rep(i, N)
  {
    a[i + 1] += a[i];
  }
  vector<long long> addA;
  rep(i, N + 1)
  {
    for (int j = i + 1; j < N + 1; j++)
      addA.push_back(a[j] - a[i]);
  }

  long long ans = 0;
  rep(i, 41)
  {
    long long temp = ans + pow(2, 40 - i);
    long long count = 0;
    rep(j, addA.size())
    {
      if ((temp & addA[j]) == temp)
        count++;
    }
    if (count >= K)
      ans = temp;
  }

  cout << ans << endl;
  return 0;
}