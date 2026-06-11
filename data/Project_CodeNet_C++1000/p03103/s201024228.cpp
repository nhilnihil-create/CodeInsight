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
  vector<ar<int, 2>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i][0] >> a[i][1];
  sort(all(a));
  int cans = 0, money = 0;
  int i = 0;
  while (cans < m) {
    int can = min(m - cans, a[i][1]);
    cans += can;
    money += a[i][0] * can;
    i++;
  }
  cout << money << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
