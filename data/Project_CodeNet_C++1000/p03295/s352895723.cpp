#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int E_N = 2*M;
  pair<int, int> E[E_N];
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    E[2*i] = make_pair(a, -1);
    E[2*i+1] = make_pair(b, a);
  }
  sort(E, E+E_N, [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  });
  bool is_open[N]; for (int i = 0; i < N; i++) is_open[i] = false;
  queue<int> Q;
  int c = 0;
  for (int i = 0; i < E_N; i++) {
    if (E[i].second >= 0) {
      if (is_open[E[i].second]) {
        c++;
        while (!Q.empty() && Q.front() < E[i].first) {
          is_open[Q.front()] = false;
          Q.pop();
        }
      }
    } else {
      Q.push(E[i].first);
      is_open[E[i].first] = true;
    }
  }
  cout << c << endl;
}