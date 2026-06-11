#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int a, b, t, cnt = 0;
  cin >> a >> b >> t;
  rep(i, 20) {
    if (a*(i+1) <= (t+0.5)) cnt++;
    else break;
  }
  cout  << b * cnt << endl;
}
