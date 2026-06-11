#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  int ans = INF;
  REP(k, N) {
    multiset<int> all;
    multiset<int> tmp;
    REP(i, N) {
      if(A[i] < A[k]) {
        int size = tmp.size() - K + 1;
        REP(j, size) {
          all.insert(*tmp.begin());
          tmp.erase(tmp.begin());
        }
        tmp.clear();
      } else {
        tmp.insert(A[i]);
      }
    }
    int size = tmp.size() - K + 1;
    REP(j, size) {
      all.insert(*tmp.begin());
      tmp.erase(tmp.begin());
    }
    tmp.clear();
    if(all.size() >= Q && *(next(all.begin(), Q-1)) - A[k] < ans) ans = *(next(all.begin(), Q-1)) - A[k];
    all.clear();
  }
  cout << ans << endl;
}