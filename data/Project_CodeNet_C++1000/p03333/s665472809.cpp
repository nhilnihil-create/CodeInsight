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
int L[100000], R[100000];
bool dead[100000];

long long solve() {
  priority_queue<P> lmax;
  priority_queue<P, vector<P>, greater<P> > rmin;
  rep(i, N) {
    lmax.push(P(L[i], i));
    rmin.push(P(R[i], i));
  }

  long long s = 0;
  int pos = 0;
  rep(i, N) dead[i] = false;
  rep(_, N) {
    if (_%2) {
      // <-
      while (dead[rmin.top()._2]) rmin.pop();
      int id = rmin.top()._2;
      dead[id] = true;
      if (R[id] < pos) s += pos-R[id], pos = R[id];
    }
    else {
      // ->
      while (dead[lmax.top()._2]) lmax.pop();
      int id = lmax.top()._2;
      dead[id] = true;
      if (pos < L[id]) s += L[id]-pos, pos = L[id];
    }
  }
  s += abs(pos);
  return s;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> L[i] >> R[i];
  long long m = solve();
  rep(i, N) L[i] = -L[i], R[i] = -R[i], swap(L[i], R[i]);
  m = max(m, solve());
  cout << m << "\n";
  return 0;
}
