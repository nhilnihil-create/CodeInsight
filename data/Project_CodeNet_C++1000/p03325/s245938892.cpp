#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll func(ll x) {
  if (x % 2 != 0) return 0;
  return 1 + func(x/2);
} 

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0;
  rep(i,n) {
    ans += func(a[i]);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}