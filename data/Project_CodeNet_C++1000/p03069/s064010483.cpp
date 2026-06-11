#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

const ll INF = 1LL << 50;

int main() {
  size_t n;
  string str;
  cin >> n >> str;
  
  size_t bs = str.find("#");
  if (bs == string::npos) {
    cout << 0 << endl;
    return 0;
  }
  ll state = 1; // black
  ll bc = 0;
  ll wc = 0;
  ll ansb = 0;
  ll answ = 0;
  for (size_t i = bs; i < n; i++) {
    if(state == 0){
      if(str[i] == '.') {
        state = 1;
        wc = 1;
      } else {
        bc++;
      }
    } else {
      if(str[i] == '#') {
        tie(ansb, answ) = P(wc + min(ansb, answ), bc + answ);
        bc = 1;
        wc = 0;
        state = 0;
      } else {
        wc++;
      }
    }
  }
  if(str[n-1] == '.')
    tie(ansb, answ) = P(wc + min(ansb, answ), bc + answ);

  cout << min(answ, ansb) << endl;
  return 0;
}
