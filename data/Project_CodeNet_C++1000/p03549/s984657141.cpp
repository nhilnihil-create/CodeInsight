#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000000;
const ll MOD = 1000000007;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, m;
  cin >> n >> m;

  int rate = pow(2, m);
  int a = 1900 * m;
  int b = (n - m) * 100;
  int ans = (a + b) * rate;

  cout << ans << endl;

  return 0;
}
