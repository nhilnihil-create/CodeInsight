#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  cin >> n;
  char c;
  map<char, int> mp;
  rep(i, n) {
    cin >> c;
    mp[c]++;
  }
  cout << (mp.size() == 3 ? "Three" : "Four") << endl;
  return 0;
}
