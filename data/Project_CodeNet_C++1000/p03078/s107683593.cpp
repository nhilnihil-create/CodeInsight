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
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  long long A[X], B[Y], C[Z];
  REP(i, X) cin >> A[i];
  REP(i, Y) cin >> B[i];
  REP(i, Z) cin >> C[i];
  sort(A, A+X);
  sort(B, B+Y);
  sort(C, C+Z);

  priority_queue<pair<long long, tuple<int, int, int>>> q;
  q.push(make_pair(A[X-1]+B[Y-1]+C[Z-1], make_tuple(X-1, Y-1, Z-1)));

  pair<long long, tuple<int, int, int>> pr;
  int cursol_A;
  int cursol_B;
  int cursol_C;
  set<tuple<int, int, int>> seen;

  REP(i, K) {
    while (true) {
      pair<long long, tuple<int, int, int>> pr = q.top(); q.pop();
      // cout << pr.first << endl;
      // cout << 1 << endl;
      int& cursol_A = get<0>(pr.second);
      int& cursol_B = get<1>(pr.second);
      int& cursol_C = get<2>(pr.second);
      // cout << cursol_A << endl;
      if (seen.count(make_tuple(cursol_A, cursol_B, cursol_C)) == 0) {
        cout << pr.first << endl;
    // cout << 1 << endl;
    seen.insert(make_tuple(cursol_A, cursol_B, cursol_C));
    // cout << 1 << endl;

    if(cursol_A >= 1) q.push(make_pair((A[cursol_A-1] + B[cursol_B] + C[cursol_C]), make_tuple(cursol_A-1, cursol_B, cursol_C)));
    if(cursol_B >= 1) q.push(make_pair((A[cursol_A] + B[cursol_B-1] + C[cursol_C]), make_tuple(cursol_A, cursol_B-1, cursol_C)));
    if(cursol_C >= 1) q.push(make_pair((A[cursol_A] + B[cursol_B] + C[cursol_C-1]), make_tuple(cursol_A, cursol_B, cursol_C-1)));
    break;

      }
    }
    
    


  }
  return 0;
}