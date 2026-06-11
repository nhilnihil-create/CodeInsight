#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = a[i] - (i + 1);
  }
  sort(b.begin(), b.end());

  for (ll i = 1; i <= n; i++)
  {
    sum += abs(a[i - 1] - (b[n / 2] + i));
  }
  cout << sum << endl;
}