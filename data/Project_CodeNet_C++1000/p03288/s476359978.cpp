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
using ll = long long;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 60;

// for each x, count
// a***b
// b=0 -> 0
// a=b -> 1
// a>b -> 1

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll r;
  cin >> r;
  if (r < 1200)
    cout << "ABC" << endl;
  else if (r < 2800)
    cout << "ARC" << endl;
  else
    cout << "AGC" << endl;
  return 0;
}
