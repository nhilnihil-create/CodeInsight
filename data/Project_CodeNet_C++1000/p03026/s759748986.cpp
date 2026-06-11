#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

vector<int> to[10000+1];
vector<bool> visited(10000+1);

void solve() {
  int N;
  cin >> N;

  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> C(N);
  for (int &c:C) {
    cin >> c;
  }

  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());

  int M = 0;
  for (int i = 1; i < C.size(); i++ ) {
    M += C[i];
  }

  queue<int> queue;
  queue.push(1);

  int ci = 0;

  vector<int> ans(N+1);
  while (!queue.empty()) {
    int i = queue.front();
    visited[i] = true;
    queue.pop();

    ans[i] = C[ci++];
    for (int t:to[i]) {
      if (!visited[t]) {
        queue.push(t);
      }
    }
  }

  cout << M << endl;
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
