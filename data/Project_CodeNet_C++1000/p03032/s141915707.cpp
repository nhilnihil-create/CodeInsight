#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N, K; cin >> N >> K;
  vector<int> V(N);
  REP(i, N) cin >> V[i];
  int R = min(N, K);
  int M = 0;
  for(int A = 0; A <= R; A++) {
    for(int B = 0; B <= R; B++) {
      if (A + B <= R) {
        vector<int> my_jewl;
        // cout << A << ' ' << B << endl;
        REP(i, A) my_jewl.push_back(V[i]);
        REP(i, B) my_jewl.push_back(V[N - 1 - i]);
        sort(ALL(my_jewl));
        // REP(i, my_jewl.size()) cout << my_jewl[i] << ' ';
        // cout << endl;

        int ans = 0;
        REP(i, my_jewl.size()) ans += my_jewl[i];
        // cout << ans << endl;
        REP(i, min((int)my_jewl.size(), K-A-B)) {
          if (my_jewl[i] < 0) ans += abs(my_jewl[i]);
        }
        M = max(M, ans);
      }
    }
  }
  cout << M << endl;
  return 0;
}