#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

int main() {
  //
  ll n, z, w;
  cin >> n >> z >> w;
  vl a(n);
  rep(i, n) cin >> a[i];
  if (n == 1) {
    cout << abs(w - a[0]) << endl;
    return 0;
  }
  cout << max(abs(a[n - 1] - w), abs(a[n - 1] - a[n - 2])) << endl;
  return 0;
}
