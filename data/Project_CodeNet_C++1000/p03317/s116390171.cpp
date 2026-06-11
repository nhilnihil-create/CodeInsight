#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll N, K, ans = 0;
  cin >> N >> K;
  vector<ll> a(N, 0);
  for (ll i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  if (N <= K)
  {
    ans = 1;
  }
  else
  {
    ans = ceil((double)(N - 1) / (K - 1));
  }

  cout << ans << endl;
}
