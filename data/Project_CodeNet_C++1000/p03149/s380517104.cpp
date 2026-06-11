#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  vector<int> a(4);
  rep(i, 4) cin >> a[i];
  sort(a.begin(), a.end());
  if(a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) cout << "YES" << endl;
  else cout << "NO" << endl;
}
