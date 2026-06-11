#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const int INF = (1<<21);
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};


int main() {
  int N; cin >> N;
  int V[N], C[N];
  for (int i = 0; i < N; ++i) cin >> V[i];
  for (int i = 0; i < N; ++i) cin >> C[i];
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (V[i] > C[i]) ans += V[i]-C[i];
  }
  cout << ans << endl;
}
