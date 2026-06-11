#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K;
  cin >> N >> K;

  vector<vector<int>> td(N);
  for (int i = 0; i < N; i++) {
    int t, d;
    cin >> t >> d;
    t--;
    td[t].push_back(d);
  }

  vector<pair<int,int>> p;
  for (int i = 0; i < N; i++) {
    if (0 < td[i].size()) {
      sort(td[i].begin(), td[i].end());
      for (int j = 0; j < td[i].size(); j++) {
        p.push_back(make_pair(td[i][j], j == (td[i].size() - 1)));
      }
    }
  }

  sort(p.begin(),p.end());

  priority_queue<int, vector<int>, greater<int>> que;

  int kind = 0;
  int choose = 0;
  long long sum = 0;
  long long answer = 0;

  for (int i = p.size() - 1; 0 <= i; i--) {
    int d = p[i].first;
    int v = p[i].second;
    sum += d;
    choose++;
    kind += v;
    if (!v) {
      que.push(d);
    }
    if (choose > K) {
      if (!que.size()) {
        break;
      }
      sum -= que.top();
      que.pop();
      choose--;
    }
    if (choose == K) {
      answer = max(answer, sum +(long long) kind * kind);
    }
  }
  
  cout << answer << endl;

  return 0;

}