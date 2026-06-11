#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int N, M;
  int X, Y;
  cin >> N >> M;
  cin >> X >> Y;
  vector<int> XP(N);
  vector<int> YP(M);
  REP(i, N) {
    cin >> XP[i];
  }
  REP(i, M) {
    cin >> YP[i];
  }
  for (int i = -99; i < Y; i++) {
    bool ok = true;
    if (i <= X || i > Y) {
      continue;
    }
    REP(j, N) {
      if (i <= XP[j]) {
        ok = false;
        break;
      }
    }
    REP(j, M) {
      if (i > YP[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
  
  return 0;
}