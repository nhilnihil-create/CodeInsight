#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<int> G[n];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> c(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  sort(c.begin(), c.end(), greater<int>());
  sum -= c[0];
  queue<int> q;
  vector<int> costs(n, -1);
  q.push(0);
  int count = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    costs[v] = c[count];
    count++;
    for (auto i : G[v]) {
      if (costs[i] == -1) {
        q.push(i);
      }
    }
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << costs[i] << endl;
  }
}
