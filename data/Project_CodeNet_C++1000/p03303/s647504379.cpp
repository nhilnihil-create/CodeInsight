#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  ll n;
  cin >> s >> n;
  rep(i, s.size()) {
    if (i%n == 0) cout << s.at(i);
  }
  cout << endl;
}