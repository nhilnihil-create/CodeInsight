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
#define ar array
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

void init() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  if (n >= m) {
    cout << 0 << endl;
    return;
  }
  for (int &i : a)
    cin >> i;
  sort(all(a));
  vi diff(m - 1);
  for (int i = 1; i < m; i++)
    diff[i - 1] = a[i] - a[i - 1];
  sort(all(diff));
  int ans = 0;
  for (int i = 0; i < m - n; i++)
    ans += diff[i];
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
