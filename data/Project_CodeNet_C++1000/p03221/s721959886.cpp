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
      prefs[i].erase(unique(prefs[i].begin(), prefs[i].end()), prefs[i].end());
    }
  }
  rep(i, m) {
    int id = lower_bound(prefs[cs[i].first].begin(), prefs[cs[i].first].end(), cs[i].second) - prefs[cs[i].first].begin();
    printf("%06d", cs[i].first);
    printf("%06d\n", id+1);
  }
  return 0;
}