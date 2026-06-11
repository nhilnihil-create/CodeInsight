#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  cin >> N;
  vector<int> C(N - 1), S(N - 1), F(N - 1);
  REP(i, N - 1) { cin >> C[i] >> S[i] >> F[i]; }
  REP(i, N) {
    int time = 0;
    for (int j = i; j < N - 1; j++) {
      if(time<S[j]){
        time = S[j] + C[j];
      }else{
        time = ((time+F[j]-1) / F[j])*F[j];
        time+=C[j];
      }
    }
    cout << time << endl;
  }
}