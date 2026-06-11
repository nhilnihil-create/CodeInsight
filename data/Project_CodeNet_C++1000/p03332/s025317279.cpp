//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const long long INF = 1e18;
const double PI = 2 * asin(1);

ll AN(ll A, ll N){
  if (N == 0) return 1;
  else{
    if (N % 2 == 0) {
      return AN(A * A % mod, N / 2) % mod;
    }else{
      return A * AN(A * A % mod, N / 2) % mod;
    }
  }
}

int main(){

  ll N; cin >> N;
  vector <ll> dir(N + 1), rev(N + 1);
  dir[0] = 1;
  for (ll i = 1; i < N + 1; i++){
    dir[i] = dir[i - 1] * i % mod;
  }
  for (ll i = 0; i < N + 1; i++){
    rev[i] = AN(dir[i], mod - 2);
  }

  ll ans = 0;
  ll A, B, K; cin >> A >> B >> K;

  for (ll i = 0; i <= N; i++){
    ll rest = K - A * i;
    if (rest >= 0 && rest % B == 0 && rest / B <= N){
      ll a = i, b = rest / B;
      ll now = dir[N];
      now *= rev[a]; now %= mod;
      now *= rev[N - a]; now %= mod;
      now *= dir[N]; now %= mod;
      now *= rev[b]; now %= mod;
      now *= rev[N - b]; now %= mod;
      ans += now; ans %= mod;
    }else if (rest < 0) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
