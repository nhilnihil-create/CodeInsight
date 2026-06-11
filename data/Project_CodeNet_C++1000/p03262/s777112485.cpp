#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n,X;
  cin >> n >> X;
  vector<int> x(n);
  rep(i,n) {
    int a;
    cin >> a;
    a = abs(a-X);
    x[i] = a;
  }
  int ans = x[0];
  rep(i,n) {
    ans = gcd(ans, x[i]);
  }
  cout << ans << endl;
  return 0;
}