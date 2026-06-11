#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int memo[1000000];
int res(int n) {
  if(n == 0) return 0;
  if(memo[n] != -1) return memo[n];
  int ans = n;
  for(int i = 1; i <= n; i *= 6) {
    ans = min(ans, res(n - i) + 1);
  }

  for(int i = 1; i <= n; i *= 9) {
    ans = min(ans, res(n - i) + 1);
  }

  return memo[n] = ans;
}

int main() {
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  if(N == 1 && M == 1) { cout << 1; return 0; } 
  if(N == 1 || M == 1) { ans = max(N, M) - 2; cout << ans; return 0;}

  ans = N * M - 2 * N - 2 * ( M - 2);

  cout << ans; 

  return 0;
}