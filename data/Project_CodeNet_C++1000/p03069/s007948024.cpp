#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> whi(n + 1, 0);
  vector<int> bla(n + 1, 0);
  rep(i, n) {
    if (s[i] == '.')
      whi[i + 1] += whi[i] + 1;
    else
      whi[i + 1] += whi[i];
    if (s[i] == '#')
      bla[i + 1] += bla[i] + 1;
    else
      bla[i + 1] += bla[i];
  }
  ll res = INF;
  for (int left = 0; left <= n; left++) {
    ll now = 0;
    now += bla[left] - bla[0];
    now += whi[n] - whi[left];
    res = min(res, now);
  }
  cout << res << endl;
}