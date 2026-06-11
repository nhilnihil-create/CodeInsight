#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<string, int>;
const int INF = 1000000007;

int main() {
  int n;
  cin >> n;
  int cnt = 1;
  pair<pair<string, int>, int> a[110];
  rep(i, n) {
    string s;
    int t;
    cin >> s >> t;
    a[i] = make_pair(make_pair(s, -t), cnt);
    cnt++;
  }
  sort(a, a + n);
  rep(i, n) { cout << a[i].second << endl; }
}
