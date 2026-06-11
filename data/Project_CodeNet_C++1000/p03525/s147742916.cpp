#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> cnt(13);
  rep(i, n) {
    int a; cin >> a;
    ++cnt[a];
  }
  ++cnt[0];

  if(cnt[0] >= 2) {
    cout << 0 << endl;
    return 0;
  }

  rep1(i, 12) {
    if(cnt[i] >= 3) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
	for(int mask = 0; mask < (1 << 13); ++mask) {
    vector<int> times;
    times.push_back(0);
    times.push_back(24);
    rep1(i, 12) {
      if(cnt[i] == 0) continue;
      else if(cnt[i] == 2) {
        times.push_back(i);
        times.push_back(24 - i);
      } else {
        if(mask & (1 << i)) {
          times.push_back(i);
        } else {
          times.push_back(24 - i);
        }
      }
    }

    sort(times.begin(), times.end());
    int minv = 1e9;
    rep1(j, times.size() - 1) {
      chmin(minv, times[j] - times[j - 1]);
    }
    chmax(ans, minv);
  }

  cout << ans << endl;
}
