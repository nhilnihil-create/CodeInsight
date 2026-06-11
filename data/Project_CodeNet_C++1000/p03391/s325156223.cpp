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
typedef pair<ll, ll> pll;
typedef pair<int, pii> pipii;

void solve() {
  int n;
  vector<pll> v; // {difference, a term}
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v.push_back({a-b, a});
  }
  sort(v.begin(), v.end());
  if(v[0].first == 0) {
    cout << "0\n";
    return;
  }
  ll ret = 0;
  ll smallest = 1e9;
  for(pll out: v) {
    ret += out.second;
    if(out.first > 0) smallest = min(smallest, out.second - out.first);
  }
  cout << ret - smallest << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
