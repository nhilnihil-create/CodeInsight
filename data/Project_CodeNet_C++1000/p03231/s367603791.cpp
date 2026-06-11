#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, l, lcm, dn, dm;
  string S, T;
  cin >> N >> M >> S >> T;
  l = (N * M) / __gcd(N, M);
  dn = l / N;
  dm = l / M;
  lcm = (dn * dm) / __gcd(dn, dm);
  for (int64_t i = 0; i < l; i += lcm)
  {
    if (S.at(i / dn) != T.at(i / dm))
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
}
