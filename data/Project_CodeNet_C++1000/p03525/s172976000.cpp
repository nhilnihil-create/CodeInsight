#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

ll mod = 1000000007;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  if (n >= 24) {
    cout << 0 << endl;
    return 0;
  }

  map<int, int> m;
  m[0] = 1;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    m[tmp]++;
  }

  if (m[0] > 1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 1; i <= 12; i++) {
    vector<int> a(23);
    int last = 0;
    bool flag = true;
    for (int j = 0; j <= 23; j++) {
      if (m[j] >= 3) {
        cout << 0 << endl;
        return 0;
      }

      if (m[j] == 0) continue;
      if (j - last >= i) {  // 前回から距離が十分ある
        // 二人いれば一人を移動させる。
        if (m[j] >= 2 && j >= 12) flag = false;
        if (m[j] >= 2) {
          m[j]--; m[24-j]++;
        }
        last = j;
        continue;
      }

      // 前回から距離が足りない
      if (m[j] - last < i) {
        if (m[j] >= 2) flag = false;
        // 反対側に移動させる
        if (j < 12) {
          m[j] = 0;
          m[24-j]++;
        } else {
          flag = false;
        }
      }
    }


    if (24 - last < i) flag = false;

    if (flag) ans = i;
  }

  cout << ans << endl;  

  return 0;
}
