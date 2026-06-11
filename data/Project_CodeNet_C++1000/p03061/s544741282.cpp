#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int N;
ll A[100010];
ll X[100010];
ll Y[100010];

int main(){
  cin >> N;
  rep(i, N) cin >> A[i];
  X[0] = A[0];
  Y[0] = A[N-1];
  rep(i, N){
    X[i+1] = gcd(X[i], A[i+1]);
    Y[i+1] = gcd(Y[i], A[(N-1)-(i+1)]);
  }
  ll ans = 0;
  ans = max(X[N-2], Y[N-2]);
  // rep(i, N) cout << X[i] << " " << Y[i] << endl;

  rep(i, N-2){
    // cout << gcd(X[i], Y[(N-1)-(i+2)]) << endl;
    ans = max(ans, gcd(X[i], Y[(N-1)-(i+2)]));
  }
  cout << ans << endl;
}
