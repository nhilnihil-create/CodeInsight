#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
vector<int> L;
int ans = 1e9;

void dfs(vector<int> V) {
  if (V.size() == N) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < N; i++) {
      if (V.at(i) == 0) a += L.at(i);
      if (V.at(i) == 1) b += L.at(i);
      if (V.at(i) == 2) c += L.at(i);
      if (V.at(i) == 3) d++;
    }
    if (!a || !b || !c) return;
    int mp = ((N - d - 3) * 10 + abs(A - a) + abs(B - b) + abs(C - c));
    ans = min(ans, mp);
    return;
  }
  for (int i = 0; i <= 3; i++) {
    V.push_back(i);
    dfs(V);
    V.pop_back();
  }
}

int main() {
  cin >> N >> A >> B >> C;
  L.resize(N);
  for (int i = 0; i < N; i++) cin >> L.at(i);
  vector<int> start;
  dfs(start);
  cout << ans << "\n";
}
