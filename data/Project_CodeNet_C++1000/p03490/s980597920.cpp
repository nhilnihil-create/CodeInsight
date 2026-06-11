#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(a) (a).begin(),(a).end()
#define SIZE(a) (int)((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using namespace std;

typedef pair<int,int> P;
struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  return s;
}


signed main()
{
  string s; cin >> s;
  int x, y; cin >> x >> y;

  int cnt = 0;
  bool x_updated = false;
  vector<int> X, Y;
  rep(i, 0, SIZE(s)) {
    if (s[i] == 'F') {
      cnt++;
    } else {
      if (x_updated) {
        Y.push_back(cnt);
      } else {
        X.push_back(cnt);
      }
      x_updated = !x_updated;
      cnt = 0;
    }
  }
  if (x_updated) {
    Y.push_back(cnt);
  } else {
    X.push_back(cnt);
  }


  vector< vector<bool> > x_list(2, vector<bool>(2*SIZE(s), false)), y_list(2, vector<bool>(2*SIZE(s), false));
  x_list[1][X[0] +SIZE(s)] = true;
  y_list[0][0 +SIZE(s)] = true;
  rep(i, 1, SIZE(X)) {
    int x_step = X[i];
    fill(ALL(x_list[(i+1) % 2]), false);
    rep(j, 0, 2*SIZE(s)) {
      if (x_list[i % 2][j]) {
        if (j - x_step >= 0) {
          x_list[(i+1) % 2][j - x_step] = true;
        }
        if (j + x_step < 2*SIZE(s)) {
          x_list[(i+1) % 2][j + x_step] = true;
        }
      }
    }
  }
  rep(i, 0, SIZE(Y)) {
    int y_step = Y[i];
    fill(ALL(y_list[(i+1) % 2]), false);
    rep(j, 0, 2*SIZE(s)) {
      if (y_list[i % 2][j]) {
        if (j - y_step >= 0) {
          y_list[(i+1) % 2][j - y_step] = true;
        }
        if (j + y_step < 2*SIZE(s)) {
          y_list[(i+1) % 2][j + y_step] = true;
        }
      }
    }
  }

  if (x_list[SIZE(X) % 2][x +SIZE(s)] && y_list[SIZE(Y) % 2][y +SIZE(s)]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
