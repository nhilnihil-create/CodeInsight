#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;
double pi = 3.14159265358979;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}

int main() {
  int n;
  cin >> n;
  vector<ll> v(5,0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    char c = s[0];
    if (c == 'M') v[0]++;
    else if (c == 'A') v[1]++;
    else if (c == 'R') v[2]++;
    else if (c == 'C') v[3]++;
    else if (c == 'H') v[4]++;
  }
  ll sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        sum += (v[i] * v[j]* v[k]);
      }
    }
  }
  printf("%lld\n", sum);
}