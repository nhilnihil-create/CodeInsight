#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mod 1000000007
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n, k;
  cin >> n >> k;
  int div = n / k;
  int ans = div * div * div;
  int cnt = 0;
  if (!(k & 1)) {
    for (int i = k / 2; i <= n; i += k) {
      cnt++;
    }
    ans += cnt * cnt * cnt;
  }
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
