#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define repi(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> red(n), blue(n);
  rep(i, n) cin >> red.at(i).first >> red.at(i).second; //red(x,y)
  rep(i, n) cin >> blue.at(i).second >> blue.at(i).first; //blue(y,x)
  sort(red.rbegin(), red.rend());
  sort(blue.begin(), blue.end());

  int ans = 0;

  rep(i,n) {
    rep(j,n) {
      if(blue.at(i).second > red.at(j).first && blue.at(i).first > red.at(j).second) {
        ans++;
        red.at(j).first = 2 * n;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}