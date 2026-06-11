#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] -= (i+1);
  sort(whole(a));
  int b;
  if (n%2==1) {
    b = a[(n-1)/2];
  }
  else {
    b = (a[n/2-1]+a[n/2])/2;
  }
  ll ans = 0;
  rep(i, n) {
    ans += (ll)(abs(a[i]-b));
  }
  cout << ans << endl;
  return 0;
}