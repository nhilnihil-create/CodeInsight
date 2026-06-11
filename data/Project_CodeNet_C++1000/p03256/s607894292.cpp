#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int n, m, deleted = 0;
string s;
bool lst[200005] = {0};
vector<int> ab[200005][2];
int cnt[200005][2] = {0};
queue<int> qu;

bool solve();

int main() {
  int a, b, i;
  cin >> n >> m;
  cin >> s;
  for(i = 0; i < m; ++i) {
    cin >> a >> b;
    --a;
    --b;
    ab[a][s[b] - 'A'].push_back(b);
    ab[b][s[a] - 'A'].push_back(a);
  }
  for(i = 0; i < n; ++i)
    for(int j = 0; j < 2; ++j) cnt[i][j] = ab[i][j].size();
  for(i = 0; i < n; ++i)
    if(cnt[i][0] == 0 || cnt[i][1] == 0) {
      qu.push(i);
      ++deleted;
      lst[i] = 1;
    }
  prians(solve());
  return 0;
}

bool solve() {
  int now, i, k, to;
  while(qu.size() > 0) {
    now = qu.front();
    qu.pop();
    for(k = 0; k < 2; ++k)
      for(i = 0; i < ab[now][k].size(); ++i) {
        to = ab[now][k][i];
        if(!lst[to]) --cnt[to][s[now] - 'A'];
        if(!lst[to] && cnt[to][s[now] - 'A'] == 0) {
          lst[to] = 1;
          qu.push(to);
          ++deleted;
          if(deleted == n) return 0;
        }
      }
  }
  return deleted != n;
}
