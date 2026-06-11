#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  int N; cin >> N;
  int M = 2, sum = 1;
  bool ok = false;
  while (sum <= N) {
    if (sum == N) {
      ok = true;
      break;
    }
    sum += M++;
  }
  if (!ok) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  vvi ans(M);
  int ini = 1;
  rep(i, M) {
    rep(j, M-1-i) {
      ans[i].pb(ini+j);
      ans[i+1+j].pb(ini+j);
    }
    ini += M-1-i;
  }

  cout << M << endl;
  rep(i, M) {
    cout << M-1;
    rep(j, M-1) {
      printf(" %ld", ans[i][j]);
    }
    cout << endl;
  }
  return 0;
}
