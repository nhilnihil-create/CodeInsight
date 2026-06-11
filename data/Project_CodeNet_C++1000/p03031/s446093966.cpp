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
  int N, M; cin >> N >> M;
  vector<vector<int>> S(M);
  vector<int> p(M);
  for (int i = 0; i < M; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int s; cin >> s; s--;
      S[i].push_back(s);
    }
  }
  for (int i = 0; i < M; ++i) cin >> p[i];
  int ans = 0;
  for (int bit = 0; bit < (1<<N); ++bit) {
    bool flag = true;
    for (int i = 0; i < M; ++i) {
      int on = 0;
      for (auto ns : S[i]) {
        if (bit & (1<<ns)) on++;
      }
      if (on % 2 != p[i]) flag = false;
    }
    if (flag) ans++;
  }
  cout << ans << endl;
}
