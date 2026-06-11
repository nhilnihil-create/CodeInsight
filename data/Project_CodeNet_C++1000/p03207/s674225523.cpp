#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <ll> v(n);
  ll res = 0;
  rep(i, n) {
    cin >> v.at(i);
    res += v.at(i);
  }
  sort(v.begin(), v.end());
  cout << res - v.at(n-1)/2 << endl;
}