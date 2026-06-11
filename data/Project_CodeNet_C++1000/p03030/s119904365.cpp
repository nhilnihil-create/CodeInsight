#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> sp;
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    pair<string, int> tmp;
    tmp.first = s;
    tmp.second = p;
    sp.emplace_back(tmp, i);
  }
  sort(sp.begin(), sp.end());
  // rep(i, n) {
  //  cout << sp[i].first << ' ' << sp[i].second << endl;
  //}
  rep(i, n) {
    rep(j, n) {
      if (sp[i].first.first == sp[j].first.first) {
        if (sp[i].first.second > sp[j].first.second) {
          pair<pair<string, int>, int> tmp = sp[i];
          sp[i] = sp[j];
          sp[j] = tmp;
        }
      }
    }
  }
  rep(i, n) cout << sp[i].second + 1 << endl;
  return 0;
}