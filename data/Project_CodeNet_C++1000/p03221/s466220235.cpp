#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

string int2str(int x) {
  string res = "";
  rep(i, 6) {
    res += x % 10 + '0';
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  rep(i, m) cin >> p[i] >> y[i];

  vector<set<P>> city(n+1);
  rep(i, m) city[p[i]].insert(make_pair(y[i], i));
  
  vector<string> id(m);
  for (int i = 1; i <= n; ++i) {
    int j = 1;
    for (auto itr = city[i].begin(); itr != city[i].end(); ++itr) {
      id[itr->second] = int2str(i) + int2str(j);
      ++j;
    }
  }
  rep(i, m) cout << id[i] << endl;
  return 0;
}