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
  for (int bit = 0; bit < (1<<N); ++bit) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; ++i) {
      if (bit & (1<<i)) {
        x += V[i];
        y += C[i];
      }
    }
    ans = max(ans, x-y);
  }
  cout << ans << endl;
}
