#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------
int N;
int a[200], b[200], c[200], d[200];
pair<int, int> red[200], blue[200];

int main() {
  cin >> N;
  priority_queue<pair<int, int>> que_red;
  rep(i, 0, N) {
    cin >> a[i] >> b[i];
    red[i] = make_pair(a[i], b[i]);
    que_red.push(red[i]);
  }

  priority_queue<pair<int, int>> que_x;
  rep(i, 0, N) {
    cin >> c[i] >> d[i];
    blue[i] = make_pair(c[i], d[i]);
    que_x.push(blue[i]);
  }

  vector<int> blue_y;

  int ans = 0;
  while (!que_red.empty()) {
    auto r = que_red.top();
    que_red.pop();

    while (!que_x.empty() && que_x.top().first > r.first) {
      auto b = que_x.top();
      que_x.pop();
      blue_y.push_back(b.second);
    }

    sort(blue_y.begin(), blue_y.end());
    vector<int> newvec;
    bool can = false;
    for (auto e : blue_y) {
      if (!can && e > r.second) {
        ans++;
        can = true;
      } else {
        newvec.push_back(e);
      }
    }
    blue_y = newvec;
  }

  cout << ans << endl;
}