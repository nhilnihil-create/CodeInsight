#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> red(n), blue(n);
  rep(i,n) cin >> red[i].first >> red[i].second;
  rep(i,n) cin >> blue[i].first >> blue[i].second;

  sort(blue.begin(), blue.end());

  rep(i,n) {
    vector<P> cand;
    rep(j,red.size()) {
      if (red[j].first < blue[i].first && red[j].second < blue[i].second) {
	cand.push_back(red[j]);
      }
    }
    if (cand.size() == 0) continue;
    sort(cand.begin(), cand.end(), [](P a, P b) {
				     return (a.second > b.second);});
    red.erase(find(red.begin(), red.end(), cand[0]));
  }
  cout << n - red.size() << endl;
  return 0;
}
