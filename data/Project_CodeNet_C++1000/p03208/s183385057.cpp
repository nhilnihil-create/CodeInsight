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
  vi h(n);
  for (int &i : h)
    cin >> i;
  sort(all(h));
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
    if (i + k-1 < n)
      ans = min(ans, h[i + k-1] - h[i]);
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
