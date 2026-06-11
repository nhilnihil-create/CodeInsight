#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, K;
  cin >> N >> K;
  long long zero_count = 0;
  long long harf_K_count = 0;
  long long ans = 0;

  rep(i, N)
  {
    if ((i + 1) % K == 0)
      zero_count++;
    if ((i + 1) % K == (K / 2))
      harf_K_count++;
  }
  if (K % 2 == 1)
  {
    ans = zero_count * zero_count * zero_count;
  }
  else
  {
    ans = zero_count * zero_count * zero_count;
    ans += harf_K_count * harf_K_count * harf_K_count;
  }

  cout << ans << endl;
  return 0;
}