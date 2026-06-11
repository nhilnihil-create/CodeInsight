#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int K;

int main() {
  cin >> K;

  vector<bool> visited(K, false);
  deque<pair<int, int>> que;
  que.push_back(make_pair(1, 1));
  // visited[1] = true;

  while (true) {
    auto p = que.front();
    que.pop_front();

    if (visited[p.first])
      continue;
    visited[p.first] = true;

    if (p.first == 0) {
      cout << p.second << endl;
      break;
    }

    if (!visited[(p.first * 10) % K]) {
      que.push_front(make_pair((p.first * 10) % K, p.second));
    }
    if (!visited[(p.first + 1) % K]) {
      que.push_back(make_pair((p.first + 1) % K, p.second + 1));
    }
  }

  return 0;
}