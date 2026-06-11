#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(int argc, char *argv[]) {
  ll n, z, w;
  cin >> n >> z >> w;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << abs(a[0] - w) << endl;
    return 0;
  }

  ll c1 = abs(a[n-2] - a[n-1]);
  ll c2 = abs(a[n-1] - w);
  
  cout << max(c1, c2) << endl;

  return 0;
}