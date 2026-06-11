#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool can(string a, int b, string c, int d) {
  if(b == a.size() && d == c.size()) return true;
  if(c[d] == 'A' && can(a, b, c, d+1)) return true;
  if(b == a.size()) return false;
  if(a[b] != c[d]) return false;
  return can(a, b+1, c, d+1);
}

void solve() {
  string s;
  cin >> s;
  bool ret = can(s, 0, "AKIHABARA", 0);
  if(ret) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}
