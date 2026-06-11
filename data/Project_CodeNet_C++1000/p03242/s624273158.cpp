#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  rep(i, s.size()) {
    if (s.at(i) == '1') cout << 9;
    else cout << 1;
  }
  cout << endl;
}