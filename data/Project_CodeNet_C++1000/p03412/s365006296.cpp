#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef priority_queue<ll, vl> decendingQueue;              //降順
typedef priority_queue<ll, vl, greater<ll>> ascendingQueue; //昇順
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

void solve(long long N, std::vector<long long> a, std::vector<long long> b) {
  const ll maxBit = 30;
  vl bitNums(maxBit);
  rep(k, 0, maxBit) {
    vl aTmp;
    vl bTmp;
    rep(n, 0, N) {
      aTmp.push_back(a[n] % (ll)pow(2, k + 1));
      bTmp.push_back(b[n] % (ll)pow(2, k + 1));
    }
    sort(all(aTmp));
    sort(all(bTmp));

    ll t = pow(2, k);
    rep(n, 0, N) {
      auto l = lower_bound(all(bTmp), t - aTmp[n]);
      auto r = lower_bound(all(bTmp), 2 * t - aTmp[n]);
      bitNums[k] += r - l;

      l = lower_bound(all(bTmp), 3 * t - aTmp[n]);
      r = lower_bound(all(bTmp), 4 * t - aTmp[n]);
      bitNums[k] += r - l;
    }
    bitNums[k] %= 2;
  }

  ll ans = 0;
  rep(k, 0, maxBit) {
    if (bitNums[k] == 1) {
      ans += pow(2, k);
    }
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  std::vector<long long> b(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &b[i]);
  }
  solve(N, std::move(a), std::move(b));
  return 0;
}
