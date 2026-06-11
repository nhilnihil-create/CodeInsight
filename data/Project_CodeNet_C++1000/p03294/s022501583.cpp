#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  ll n;
  ll sum = 0;

  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  rep(i, n) sum += a.at(i) - 1;

  cout << sum;
}
