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
  int n;
  cin >> n;
  vi a(n);
  for (int &i : a)
    cin >> i;
  int ans = 0;
  vi l(n + 1), r(n + 1);
  for (int i = 0; i < n; i++)
    l[i + 1] = __gcd(l[i], a[i]);
  for (int i = n-1; i >= 0; i--)
    r[i] = __gcd(r[i + 1], a[i]);
  for (int i = n - 1; i >= 0; i--)
    ans = max(ans, __gcd(l[i], r[i + 1]));
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
