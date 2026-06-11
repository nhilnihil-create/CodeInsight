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
string S;
int X[1<<26];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> S;
  N = S.length();
  rep(i, 1<<26) X[i] = INF;
  X[0] = 0;
  int b = 0;
  rep(i, N) {
    b ^= 1<<(S[i]-'a');
    rep(k, 26) X[b] = min(X[b], X[b^(1<<k)]+1);
  }
  cout << max(X[b], 1) << "\n";
  return 0;
}
