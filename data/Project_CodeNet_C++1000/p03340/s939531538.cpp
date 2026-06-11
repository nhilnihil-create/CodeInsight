#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  vector<int> bit_count(20, 0);
  vector<int> max_bit_count(N + 1, 0);

  long long ans = 0;
  rep(i, N)
  {
    int n = A[i];
    int bit = 0;

    int max_count = 0;
    int max_max_count = 0;
    while (n != 0)
    {
      if (n & 1)
      {
        max_count = max(max_count, bit_count[bit]);
        bit_count[bit] = i + 1;
      }
      n = n >> 1;
      bit++;
    }
    max_bit_count[i + 1] = max(max_bit_count[i], max_count);
    long long num = i - max_bit_count[i + 1] + 1;
    ans += num;
  }
  cout << ans << endl;
  return 0;
}