#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(ll N, ll A, ll B, ll C, ll D, ll E) {
  ll bn = min(min(min(A, B), min(C, D)), E); // bottle neck
  cout << (N / bn + (N % bn ? 1 : 0) + 4) << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  ll D;
  cin >> D;
  ll E;
  cin >> E;

  solve(N, A, B, C, D, E);

  return 0;
}
