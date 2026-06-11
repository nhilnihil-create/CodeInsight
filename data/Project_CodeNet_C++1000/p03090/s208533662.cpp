#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int mod = int(1e+9) + 7;


int main() {
  int n;
  cin >> n;
  int sum = 0;
  if (n % 2 == 0) {
    sum = 1 + n;
  } else {
    sum = n;
  }

  int num = 0;
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    for (int j = i+1; j <= n; j++) {
      if (i + j == sum) continue;
      num++;
      ans.emplace_back(i, j);
    }
  }

  cout << num << endl;
  for (auto& p : ans) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
