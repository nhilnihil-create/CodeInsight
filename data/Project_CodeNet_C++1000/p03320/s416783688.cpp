#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef pair<ll, double> pld;
typedef vector<pii> vii;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MAX_N = 1;

set<pld> candis;
vi ans;

ll S(ll x) {
  ll res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

void init() {
  for (int i = 1; i < 1000; i++) {
    for (int j = 0; j < 14; j++) {
      ll tmp = i;
      for (int k = 0; k < j; k++) {
        tmp *= 10;
        tmp += 9;
      }
      candis.insert(mp(tmp, (double)tmp/S(tmp)));
    }
  }

  double mn = INF;
  for (set<pld>::reverse_iterator it = candis.rbegin(); it != candis.rend(); ++it) {
    if (it->ss <= mn) {
      mn = it->ss;
      ans.pb(it->ff);
    }
  }
  reverse(ans.begin(), ans.end());
}

int main() {
  ll K; cin >> K;
  init();
  for (int i = 0; i < K; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
