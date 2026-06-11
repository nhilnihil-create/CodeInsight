#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, m;
  cin >> n >> m;
  vector <ll> v(n);
  ll res = 0;
  rep(i, n) {
    cin >> v.at(i);
    m -= v.at(i);
    res++;
  }
  sort(v.begin(), v.end());
  while (m >= v.at(0)) {
    res++;
    m -= v.at(0);
  }
  cout << res << endl;
}