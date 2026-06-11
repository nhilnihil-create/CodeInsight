#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll l[200005];
ll pref[200005];
void solve() {
  int n;
  ll x;
  cin >> n >> x;
  ll ret = n * x;
  vector<ll> scale;
  scale.push_back(5);
  scale.push_back(5);
  while(scale.size() <= n) {
    scale.push_back(scale.back() + 2);
  }
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    pref[i+1] = pref[i] + l[i];
  }
  ll inc = 9e18;
  for(int k = 1; k <= n; k++) {
    int curr = n;
    vector<ll> amts;
    while(curr > 0) {
      int next = max(0, curr - k);
      amts.push_back(pref[curr] - pref[next]);
      curr = next;
    }
    ll cand = 0;
    for(int i = 0; i < amts.size(); i++) {
      ll maxCan = (9e18 - cand) / amts[i];
      if(scale[i] >= maxCan) {
        cand = 9e18;
        break;
      }
      cand += amts[i] * scale[i];
    }
    inc = min(inc, (ll)(cand + x * k));
  }
  cout << ret + inc << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
