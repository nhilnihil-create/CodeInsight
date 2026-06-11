#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
template <typename T>
ll gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  ll d = gcd(b, a % b);
  return d;
}
struct Segment_Tree {
  // 随時評価セグ木
  // 値を渡すときは0-indexed，半閉区間で動作させる
  vector<int> A;
  int N;
  Segment_Tree(int x) {
    int i = 1;
    while (i <= x) {
      i = i << 1;
    }
    N = i;
    A.resize(2 * i + 1, 0);
  }
  void ValueUpdate(int id) {
    //ここを随時書き換える
    int prev = A[id];
    //区間内和
    A[id] = gcd(A[id << 1 | 0], A[id << 1 | 1]);
    if (id == 1 || prev == A[id]) return;
    ValueUpdate(id >> 1);
  }
  void ValueSet(int id, int x) {
    //値の入力は0-indexed
    A[N + id] = x;
    ValueUpdate((N + id) >> 1);
  }
  int Query(int l, int r, int nowl = 0, int nowr = -1, int id = 1) {
    if (nowr == -1) nowr = N;
    if (nowr <= l || r <= nowl) return 0;
    if (l <= nowl && nowr <= r || nowr == nowl) return A[id];
    return gcd(Query(l, r, nowl, nowl + (nowr - nowl) / 2, id << 1 | 0),
               Query(l, r, nowl + (nowr - nowl) / 2, nowr, id << 1 | 1));
  }
};
int main() {
  int N;
  cin >> N;
  Segment_Tree seg(N);
  REP(i, N) {
    int a;
    cin >> a;
    seg.ValueSet(i, a);
  }
  int ans = 0;
  for (int i = 1; i < N - 1; i++) {
    int tmp = gcd(seg.Query(0, i), seg.Query(i + 1, N));
    ans = max(ans, tmp);
  }
  ans = max<ll>(seg.Query(1, N), ans);
  ans = max<ll>(seg.Query(0, N - 1), ans);
  cout << ans << endl;
}