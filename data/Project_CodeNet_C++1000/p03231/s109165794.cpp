#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int g = gcd(n,m);
  int N = n/g;
  int M = m/g;
  rep(i,g) {
    if(s[i*N]!=t[i*M]) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << lcm(n,m) << endl;
  return 0;
}
