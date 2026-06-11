#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> p;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define srep(i, from, to) for(int i = from; i < (int)(to); i++)
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template <class T> bool chmax(T &a, const T &b) {
  if(a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if(b < a) {
    a = b;
    return 1;
  }
  return 0;
}

vector<pair<ll, int>> primefactors(ll n) {
  vector<pair<ll, int>> res;
  int sq = sqrt(n);
  for(int x = 2; x <= sq; x++) {
    int cnt = 0;
    while(n % x == 0) {
      cnt++;
      n /= x;
    }
    res.push_back(make_pair(x, cnt));
  }
  if(n > 1) res.push_back(make_pair(n, 1));
  return res;
}
ll pfcount[100];

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    // int x = i;
    // for(int y = 2; y * y <= x; y++) {
    //   while(x % y == 0) {
    //     x /= y;
    //     pfcount[y]++;
    //   }
    // }
    // if(x > 1) pfcount[x]++;
    vector<pair<ll, int>> res = primefactors(i);
    for(auto pf : res) {
      pfcount[pf.first] += pf.second;
    }
  }

  ll ans = 0;
  // x^2 * y^4 * z^4
  for(int i = 1; i < 100; i++) {
    if(pfcount[i] < 2) continue;
    for(int j = 1; j < 100; j++) {
      if(pfcount[j] < 4) continue;
      for(int k = 1; k < 100; k++) {
        if(i == j || i == k || j == k) continue;
        if(k > j) continue;
        if(pfcount[k] < 4) continue;
        ans++;
      }
    }
  }

  // x^2 * y^24
  for(int i = 1; i < 100; i++) {
    if(pfcount[i] < 2) continue;
    for(int j = 1; j < 100; j++) {
      if(i == j) continue;
      if(pfcount[j] < 24) continue;
      ans++;
    }
  }

  // x^4 * y^14
  for(int i = 1; i < 100; i++) {
    if(pfcount[i] < 4) continue;
    for(int j = 1; j < 100; j++) {
      if(i == j) continue;
      if(pfcount[j] < 14) continue;
      ans++;
    }
  }

  // x^74
  for(int i = 1; i < 100; i++) {
    if(pfcount[i] < 74) continue;
    ans++;
  }

  cout << ans << endl;
  return 0;
}
