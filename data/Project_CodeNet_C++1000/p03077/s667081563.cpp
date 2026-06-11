#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> a(5);
  for (int i = 0; i < 5; i++)
    cin >> a[i];
  ll mn = *min_element(begin(a), end(a));
  ll g = (n + mn - 1) / mn;
  cout << 4 + g << '\n';
  return 0;
}