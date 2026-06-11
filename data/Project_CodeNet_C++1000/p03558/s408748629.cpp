#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  vector<uint64_t> costs(k, INT_MAX);
  priority_queue<pair<uint64_t, int>, vector<pair<uint64_t, int>>,
                 greater<pair<uint64_t, int>>>
      q;
  costs[1] = 0;
  q.push(make_pair(0, 1));
  while (!q.empty()) {
    auto v = q.top();
    q.pop();
    int byten = (v.second * 10) % k;
    if (v.first < costs[byten]) {
      costs[byten] = v.first;
      q.push(make_pair(v.first, byten));
    }
    int next = (v.second + 1) % k;
    if (v.first + 1 < costs[next]) {
      costs[next] = v.first + 1;
      q.push(make_pair(v.first + 1, next));
    }
  }

  cout << costs[0] + 1 << "\n";
}
