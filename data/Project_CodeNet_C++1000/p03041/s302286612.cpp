#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, m; cin >> n >> m;
  rep(i, n) {
    char c; cin >> c;
    if (i+1 == m) {
      ll num = c - 'A';
      c = num + 'a';
    }
    cout << c;
  }
  cout << endl;
}