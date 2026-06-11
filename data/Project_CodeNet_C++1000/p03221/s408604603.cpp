#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n, m;
  cin >> n >> m;

  map<ll, vector<Pl>> pref;
  rep(i, m) {
    ll p, y;
    cin >> p >> y;
    pref[p].push_back(Pl(y, i));
  }

  vector<Pl> city(m);

  for (auto var : pref) {
    vector<Pl> cityList = var.second;
    sort(cityList.begin(), cityList.end());
    rep(i, ll(cityList.size())) {
      city[cityList[i].second] = Pl(var.first, i+1);
    }
  }

  rep(i, m)
    printf("%06lld%06lld\n", city[i].first, city[i].second);

  return 0;
}
