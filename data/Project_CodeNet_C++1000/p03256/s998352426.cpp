#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>

using namespace std;

char buff[312345];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", buff);
  string s = buff;
  vector<vector<int>> graph(n);
  vector<int> samedeg(n), diffdeg(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    if (s[a] == s[b]) {
      samedeg[a]++;
      samedeg[b]++;
    }
    else {
      diffdeg[a]++;
      diffdeg[b]++;
    }
  }
  queue<int> removeQ;
  vector<bool> alive(n, true);
  for (int i = 0; i < n; i++) {
    if (samedeg[i] == 0 || diffdeg[i] == 0) {
      removeQ.push(i);
      alive[i] = false;
    }
  }
  while (!removeQ.empty()) {
    int cur = removeQ.front(); removeQ.pop();
    for (auto next : graph[cur]) {
      if (!alive[next]) continue;
      if (s[cur] == s[next]) {
        samedeg[next]--;
      }
      else {
        diffdeg[next]--;
      }
      if (samedeg[next] == 0 || diffdeg[next] == 0) {
        removeQ.push(next);
        alive[next] = false;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (alive[i]) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
