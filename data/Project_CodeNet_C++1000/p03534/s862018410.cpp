#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  string s; cin >> s;
  vll abc(3, 0);
  REP(i, s.size()) abc[s[i] - 'a']++;
  sort(abc.begin(), abc.end());
  if (abc[2]-abc[0] <= 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
