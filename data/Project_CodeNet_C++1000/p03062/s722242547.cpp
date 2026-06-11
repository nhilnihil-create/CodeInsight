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
  ll sum = 0, neg = 0;
  rep(i, n) {
    cin >> v.at(i);
    if (v.at(i) < 0) {
      neg++;
      v.at(i) = abs(v.at(i));
    }
    sum += v.at(i);
  }
  sort(v.begin(), v.end());
  if (neg%2) {
    cout << sum - 2*v.at(0) << endl;
  }
  else cout << sum << endl;
}