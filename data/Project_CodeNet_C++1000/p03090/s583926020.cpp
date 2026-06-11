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
  int N; cin >> N;
  if (N % 2 == 0) {
    cout << (N-2) * N / 2 << endl;
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i + j != N+1) {
          cout << i << ' ' << j << endl;
        }
      }
    }
  }

  else {
    cout << (N-1) * (N-1) / 2 << endl;
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (j != N && i + j != N) cout << i << ' ' << j << endl;
        if (j == N) cout << i << ' ' << j << endl;
      }
    }
  }
  return 0;
}