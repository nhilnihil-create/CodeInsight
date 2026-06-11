#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int X[100000];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  int mx = -1;
  rep(i, N) cin >> X[i], mx = max(mx, X[i]);
  P cand = P(INF, INF);
  rep(i, N) if (X[i] != mx) cand = min(cand, P(abs(2*X[i]-mx), X[i]));
  cout << mx << " " << cand._2 << "\n";
  return 0;
}
