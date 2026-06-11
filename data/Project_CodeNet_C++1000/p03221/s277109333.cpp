#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> data(m);
  vector<vector<int>> s(n+1);
  rep(i,0,m) {
    int p,y;
    cin >> p >> y;
    data[i] = P(p,y);
    s[p].push_back(y);
  }
  map<P,int> ans;
  rep(i,1,n+1) {
    if ((int)s[i].size() == 0) continue;
    sort(s[i].begin(), s[i].end());
    rep(j,0,(int)s[i].size()) {
      ans[P(i,s[i][j])] = j+1;
    }
  }
  rep(i,0,m) {
    int k = ans[data[i]];
    printf("%06d",data[i].first);
    printf("%06d\n",k);
  }
  return 0;
}
