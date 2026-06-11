#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define INF 50

int main() {
  int K; cin >> K;
  vector<int> dist(K, INF);
  dist[1] = 1;
  deque<int> deq = {1};
  while (!deq.empty()) {
    int v = deq.front(); deq.pop_front();
    int u = (v * 10) % K, t = (v + 1) % K;
    if (dist[u] > dist[v]) {
      dist[u] = dist[v];
      deq.push_front(u);
    }
    if (dist[t] > dist[v] + 1) {
      dist[t] = dist[v] + 1;
      deq.push_back(t);
    }
  }
  cout << dist[0] << endl;
}