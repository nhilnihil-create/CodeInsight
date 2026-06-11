#include <algorithm>
#include <iostream>
// #include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef greater<int> gi;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  int a[n];
  REP(i, n) cin >> a[i];
  int ans = 2000000000;
  for (int y : a) {
    vi vec;
    priority_queue<int, vi, gi> que;
    REP(i, n + 1) {
      if (i == n || a[i] < y) {
        sort(ALL(vec));
        int len = vec.size();
        REP(j, len - k + 1) que.push(vec[j]);
        vec.clear();
      } else {
        vec.push_back(a[i]);
      }
    }
    if (que.size() < q) continue;
    REP(i, q - 1) que.pop();
    int x = que.top();
    ans = min(ans, x - y);
  }
  cout << ans << endl;
  return 0;
}