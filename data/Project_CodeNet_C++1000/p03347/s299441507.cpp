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
  long long N;
  cin >> N;
  long long A[N];
  REP(i, N) cin >> A[i];
  bool flag = false;
  REP(i, N) if(A[i] > i) flag = true;
  if(flag) cout << -1 << endl;
  else {
    // int cursol = N-1;
    long long target = A[N-1];
    long long ans = A[N-1];
    // while (cursol >= 0) {
    //   if (A[cursol] == target) {
    //     cursol--;
    //   }
    //   else {
    //     cursol--;
    //     target = A[cursol];
    //     ans++;
    //   }
    //   target--;
    // }
    for(int cursol = N-1; cursol >= 0; cursol--) {
      // cout << A[cursol] << ' ' << target << endl;
      if (A[cursol] == target) {}
      else if (A[cursol] < target) {
        cout << -1 << endl;
        return 0;
      }
      else {
        target = A[cursol];
        ans += target;
      }
      target--;
    }
    cout << ans << endl;
  }
  return 0;
}