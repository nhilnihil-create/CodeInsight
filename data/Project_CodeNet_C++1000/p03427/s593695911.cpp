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

int keta(ll x) {
  if (x == 0) return 0;
  else return keta(x/10) + 1;
}

bool func(ll n) {
  if (n%10 == n) return true;
  return (n%10 == 9) && func(n/10);
}

ll lef(ll n) {
  if (n%10 == n) return n;
  return lef(n/10);
}

void solve() {
  ll n;
  cin >> n;
  int k = keta(n);
  bool b = func(n);
  int l = lef(n);
  if (n < 10) {
    cout << n << endl;
    return;
  }
  int ans = (k-1) * 9 + l;
  if (b) cout << ans << endl;
  else cout << ans - 1 << endl;
}

int main() {
  solve();
  return 0;
}