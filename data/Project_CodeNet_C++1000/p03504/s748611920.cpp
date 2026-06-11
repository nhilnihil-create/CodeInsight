#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main() {
  int N, C; cin >> N >> C;
  vector<priority_queue<P, vector<P>, greater<P>>> p(C);
  for (int i = 0; i < N; i++) {
    int s, t, c; cin >> s >> t >> c;
    p[c-1].push(P(s, t));
  }

  auto comp = [](P a, P b) { return a.first > b.first;};
  priority_queue<P, vector<P>, decltype(comp)> que(comp);
  for (int i = 0; i < C; i++) {
    if (p[i].empty()) continue;
    P time = p[i].top(); p[i].pop();
    while (!p[i].empty()) {
      if (time.second == p[i].top().first) {
        time.second = p[i].top().second; p[i].pop();
      }
      else {
        que.push(time);
        time = p[i].top(); p[i].pop();
      }
    }
    que.push(time);
  }

  priority_queue<int, vector<int>, greater<int>> rec;
  rec.push(que.top().second); que.pop();
  while (!que.empty()) {
    if (rec.top() < que.top().first) rec.pop();
    rec.push(que.top().second); que.pop();
  }
  cout << rec.size() << endl;
}