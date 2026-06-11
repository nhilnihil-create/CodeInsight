#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() { int N;
  cin >> N;
  vector<int> V(N), C(N);
  REP(i, N) cin >> V[i];
  REP(i, N) cin >> C[i];
  ll X = 0, Y = 0;
  REP(i,N){
    if(C[i]<V[i]){
      X += V[i], Y += C[i];
    }
  }
  cout << X - Y << endl;
}