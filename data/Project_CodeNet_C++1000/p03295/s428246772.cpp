#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int M = 100000;

int n, m;
P war[M];

int main() {
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    war[i] = make_pair(b, a);
  }
  sort(war, war + m);
  int x = 0;
  int ans = 0;
  rep(i, m) {
    if (war[i].second < x) continue;
    x = war[i].first;
    ans++;
  }
  cout << ans << endl;
  return 0;
}