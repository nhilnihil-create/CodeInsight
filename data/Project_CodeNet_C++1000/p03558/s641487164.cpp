#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (long (i) = 0; (i) < (n); (i)++)
using namespace std;

int K;
bool searched[100000];

void solve() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 1));
  while (1) {
    auto x_and_ans = q.front();
    q.pop();
    int x = x_and_ans.first;
    while (!searched[x]) {
      if (x == 0) {
        cout << x_and_ans.second << endl;
        return;
      }
      searched[x] = true;
      x = (x * 10) % K;
      pair<int, int> new_pair (x+1, x_and_ans.second+1);
      q.push(new_pair);
    }
  }
}

int main() {
  cin >> K;

  solve();
  return 0;
}
