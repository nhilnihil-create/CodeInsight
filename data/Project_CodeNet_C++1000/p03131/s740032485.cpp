#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t K, A, B;
  cin >> K >> A >> B;
  int64_t ans = K + 1; // 叩いて増やした場合
  if (B - A <= 2 || (1 + K) <= A)
  {
    cout << ans << endl;
  }
  else
  {
    int64_t plus = B - A, init = A - 1;
    cout << A + plus * ((K - init) / 2) + (K - init) % 2 << endl;
  }
}
