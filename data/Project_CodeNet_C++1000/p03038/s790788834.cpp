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
  vector<pair<int,int>> v;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    v.push_back(make_pair(a, 1));
  }
  for (int i = 0; i < M; ++i) {
    int b, c; cin >> b >> c;
    v.push_back(make_pair(c, b));
  }
  sort(v.begin(), v.end(), greater<pair<int,int>>());
  long long ans = 0;
  int idx = 0;
  for (int i = 0; i < N; ++i) {
    ans += v[idx].first;
    v[idx].second--;
    if (v[idx].second == 0) idx++;
  }
  cout << ans << endl;
}
