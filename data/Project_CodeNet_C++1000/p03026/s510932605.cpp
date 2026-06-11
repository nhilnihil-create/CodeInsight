#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> c;
vector<int> num;
queue<pair<int, int>> q;
int idx = 1;
int sum = 0;

void bfs(int current, int parent) {
  for (int nx : G.at(current)) {
    if (nx == parent) continue;
    num.at(nx) = c.at(idx);
    idx++;
    sum += min(num.at(current), num.at(nx));
    q.push(make_pair(nx, current));
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  c.resize(N);
  num.resize(N);
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  for (int i = 0; i < N; i++) cin >> c.at(i);
  sort(c.begin(), c.end(), greater<int>());
  num.at(0) = c.at(0);
  q.push(make_pair(0, -1));
  while (!q.empty()) {
    bfs(q.front().first, q.front().second);
    q.pop();
  }
  cout << sum << endl;
  for (int i = 0; i < N-1; i++) cout << num.at(i) << " ";
  cout << num.at(N-1) << endl;
}