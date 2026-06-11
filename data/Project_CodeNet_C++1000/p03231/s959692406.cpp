#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
ll gcd(ll a, ll b) {
  if (a < b) {
    swap(a, b);
  }
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int main() {
  ll N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  ll L = lcm(N, M);
  ll n = N / gcd(N, M), m = M / gcd(N, M);
  REP(i, gcd(N, M)) {
    if (S[i * n] != T[i * m]) {
      L = -1;
    }
  }
  cout << L << endl;
}