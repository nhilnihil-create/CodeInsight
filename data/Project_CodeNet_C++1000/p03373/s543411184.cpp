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

void solve(long long A, long long B, long long C, long long X, long long Y) {
  ll ans = INF;
  rep(c, 0, 2 * max(X, Y) + 1) {
    ll tmp = C * c;
    tmp += max(0ll, X - c / 2) * A;
    tmp += max(0ll, Y - c / 2) * B;
    ans = min(ans, tmp);
  }
  print(ans);
}

int main() {
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  long long C;
  scanf("%lld", &C);
  long long X;
  scanf("%lld", &X);
  long long Y;
  scanf("%lld", &Y);
  solve(A, B, C, X, Y);
  return 0;
}
