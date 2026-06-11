#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int gcd(int a, int b) {
  if (a % b == 0) return b;
  else return gcd(b, a%b);
}

int main() {
  int n, X; cin >> n >> X;
  vector<int> x(n+1), dx(n+1);
  rep(i,n+1) {
    if (i == 0) {
      x[i] = X;
      continue;
    }
    cin >> x[i];
    dx[i] = abs(x[i] - x[i-1]);
  }

  int gx = gcd(dx[2], dx[1]);
  int i = 3;
  while (i<n) {
    gx = gcd(gx, dx[i++]);
  }
  cout << gx << endl;
  return 0;
}