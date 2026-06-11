#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
  int N, Y;
  cin >> N >> Y;

  rep(man, N + 1)
  {
    rep(gosen, N + 1)
    {
      int sen = N - man - gosen;
      int sum = man * 10000 + gosen * 5000 + sen * 1000;
      if (sen >=0 && N >= sen && sum == Y)
      {
        printf("%d %d %d", man, gosen, sen);
        return 0;
      }
    }
  }
  cout << "-1 -1 -1";
}
