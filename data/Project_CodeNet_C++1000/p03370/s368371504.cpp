#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+18;
int main()
{
  int n, x;
  cin >> n >> x;
  int ans = n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    x -= a[i];
  }
  sort(whole(a));
  ans += (x/a[0]);
  cout << ans << endl;
  return 0;
}