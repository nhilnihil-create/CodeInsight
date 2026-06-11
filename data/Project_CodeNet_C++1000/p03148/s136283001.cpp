#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n,k;
  cin >> n >> k;

  vector<pair<int,int>> sushi(n);
  for (int i = 0; i < n; i++) {
    cin >> sushi[i].second >> sushi[i].first;
  }
  sort(sushi.rbegin(),sushi.rend());

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> que;
  vector<int> cnt(n + 1, 0);
  int answer = 0;
  int kind = 0;
  for (int i = 0; i < k; i++) {
    int val = sushi[i].first;
    int x = sushi[i].second;
    que.emplace(val, x);
    answer += val;
    if(cnt[x] == 0) kind++;
    cnt[x]++;
  }
  answer += kind * kind;

  int tmp = answer;
  for (int i = k; i < n; i++) {
    int new_val = sushi[i].first;
    int new_x = sushi[i].second;

    //すでにその種類の寿司が集合にある
    if(cnt[new_x] > 0) continue;

    int old_val = 0;
    int old_x = 0;

    //どれを抜くか
    while (!que.empty()) {
      pair<int,int> p = que.top();
      if(cnt[p.second] > 1 && new_x != p.second) {
        old_val = p.first;
        old_x = p.second;
        que.pop();
        break;
      }
      que.pop();
    }

    if(old_x == 0) break;

    cnt[old_x]--;
    cnt[new_x]++;

    tmp -= kind * kind;
    kind++;
    tmp += kind * kind;
    tmp -= old_val;
    tmp += new_val;

    answer = max(answer, tmp);
  }

  cout << answer << '\n';
}
