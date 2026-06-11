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
  priority_queue<pair<int, int>> PQ;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    PQ.push(make_pair(a, 1));
  }
  for (int i = 0; i < M; ++i) {
    int b, c; cin >> b >> c;
    PQ.push(make_pair(c, b));
  }
  long long ans = 0;
  int cnt = 0;
  while (true) {
    pair<int, int> t = PQ.top();
    for (int i = 0; i < t.second; ++i) {
      ans+= t.first;
      cnt++;
      if (cnt == N) break;
    }
    PQ.pop();
    if (cnt == N) break;
  }
  cout << ans << endl;
}
