#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, int> mp_full, mp_odd, mp_eve;
  rep(i, 0, n) {
    int v;
    cin >> v;
    mp_full[v]++;
    if (i & 1)
      mp_odd[v]++;
    else
      mp_eve[v]++;
  }

  int half = n / 2;
  if ((int)mp_full.size() == 1) {
    cout << half << endl;
  } else {
    vector<P> oddv, evev;
    for (auto odd : mp_odd)
      oddv.push_back(make_pair(odd.second, odd.first));
    for (auto eve : mp_eve)
      evev.push_back(make_pair(eve.second, eve.first));

    sort(oddv.rbegin(), oddv.rend());
    sort(evev.rbegin(), evev.rend());
    int on = (int)oddv.size(), en = (int)evev.size();

    int odd_max = 0, eve_max = 0;
    if (oddv[0].second == evev[0].second) {
      if (on == 1) {
        odd_max = oddv[0].first;
        eve_max = evev[1].first;
      } else if (en == 1) {
        odd_max = oddv[1].first;
        eve_max = evev[0].first;
      } else {
        if (oddv[1].first > evev[1].first) {
          odd_max = oddv[1].first;
          eve_max = evev[0].first;
        } else {
          odd_max = oddv[0].first;
          eve_max = evev[1].first;
        }
      }
    } else {
      odd_max = oddv[0].first;
      eve_max = evev[0].first;
    }

    cout << (half - odd_max) + (half - eve_max) << endl;
  }
}
