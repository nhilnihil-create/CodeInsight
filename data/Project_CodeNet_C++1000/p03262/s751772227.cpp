#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  rep(i, N) cin >> x[i];
  
  ll max_d = abs(X - x[0]);
  for (int i = 1; i < N; ++i) max_d = gcd(max_d, abs(X - x[i]));
  cout << max_d << endl;
  return 0;
}