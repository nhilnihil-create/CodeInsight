#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll N, A, B, C;
vector<ll> v_list;

ll dfs(ll i, ll a, ll b, ll c) {
  if (i == N) {
    if (a == 0 || b == 0 || c == 0) {
      return INF;
    }

    return abs(A - a) + abs(B - b) + abs(C - c) - 30;
  }

  ll v = v_list[i];

  ll r0 = dfs(i + 1, a, b, c);
  ll r1 = dfs(i + 1, a + v, b, c) + 10;
  ll r2 = dfs(i + 1, a, b + v, c) + 10;
  ll r3 = dfs(i + 1, a, b, c + v) + 10;

  return min(min(min(r0, r1), r2), r3);
}

int main() {
  scanf("%lld %lld %lld %lld", &N, &A, &B, &C);

  v_list = vll(N);

  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    v_list[i] = v;
  }

  cout << dfs(0, 0, 0, 0) << endl;
}
