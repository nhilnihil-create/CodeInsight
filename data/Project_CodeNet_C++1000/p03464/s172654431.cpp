#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

vector<ll> A(100005, 0);

int main() {
  int K;
  cin >> K;

  rep0(i, K) cin >> A[i];

  ll MIN = 2, MAX = 2, temp;
  repR(i, 0, K) {
    // cout << i << SP << MIN << SP << MAX << BR;
    temp = ((MIN + A[i] - 1) / A[i]) * A[i];
    if (temp - (temp % A[i]) > MAX) {
      cout << "-1\n";
      return 0;
    }
    MIN = temp;

    temp = (MAX / A[i]) * A[i] + A[i] - 1;
    if (temp - (temp % A[i]) < MIN) {
      cout << "-1\n";
      return 0;
    }
    MAX = temp;
  }

  cout << MIN << SP << MAX << BR;
  return 0;
}