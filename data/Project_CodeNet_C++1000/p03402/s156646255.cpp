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
const ll INF = 1LL << 60;

int main() {
  //
  ll a, b;
  cin >> a >> b;
  ll k = 50;
  vector<string> data(2 * k, string(2 * k, '.'));
  rep(i, k) {
    rep(j, 2 * k) { data[i][j] = '#'; }
  }
  ll black = 0, white = 0;
  while (white < a - 1) {
    int i = white / (k / 2);
    int j = 4 * (white % (k / 2)) + 2 * (i & 1);
    data[i][j] = '.';
    white++;
  }
  while (black < b - 1) {
    int i = 2 * k - 1 - (black / (k / 2));
    int j = 4 * (black % (k / 2)) + 2 * (i & 1);
    data[i][j] = '#';
    black++;
  }
  cout << 100 << " " << 100 << endl;
  rep(i, 2 * k) {
    rep(j, 2 * k) { cout << data[i][j]; }
    cout << endl;
  }
  return 0;
}
