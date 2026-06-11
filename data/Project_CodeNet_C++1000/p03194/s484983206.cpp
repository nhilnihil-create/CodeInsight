#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
int prime[1000005];

int main()
{
  ll N, P;
  scanf("%lld %lld", &N, &P);
  if (N == 1)
  {
    cout << P << endl;
    return 0;
  }
  if (N * N > P)
  {
    cout << 1 << endl;
    return 0;
  }
 
  ll O = P;
  for (ll i = 2; i * i <= P + 2; i++)
  {
    ll j = i;
    while (P % j == 0)
    {
      P /= j;
      prime[j]++;
    }
  }
  if (O == P)
  {
    cout << 1 << endl;
    return 0;
  }
  if (P != 1 && P <= 100000)
    prime[P]++;

  ll ans = 1;
  for (ll i = 2; i * i <= O + 2; i++)
  {
    if (prime[i] >= N)
    {
      int num = prime[i] / N;
      ll nnum = 1;
      rep(j, num) nnum *= i;
      ans *= nnum;
    }
  }
  cout << ans << endl;
  return 0;
}
