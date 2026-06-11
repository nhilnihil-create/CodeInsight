#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string ser(string seq) {
  if (seq.size() == 6) {
    return seq;
  }
  return ser('0' + seq);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> prefs(n+1, vector<ll>(0));
  vector<map<ll, int>> mps(n+1);
  vector<pair<int, ll>> cs;
  rep(i, m) {
    int x;
    ll y;
    cin >> x >> y;
    cs.push_back(make_pair(x, y));
    cs[i].first;
    prefs[cs[i].first].push_back(cs[i].second);
  } 
  rep(i, n+1) {
    if (prefs[i].size() > 0) {
      sort(prefs[i].begin(), prefs[i].end());
      rep(j, prefs[i].size()) {
        mps[i][prefs[i][j]] = j+1;
      }
    }
  }
  rep(i, m) {
    int ord = mps[cs[i].first][cs[i].second];
    cout << ser(to_string(cs[i].first)) + ser(to_string(ord)) << endl;
  }
  return 0;
}