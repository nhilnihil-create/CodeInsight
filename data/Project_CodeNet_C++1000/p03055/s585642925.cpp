#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, r = 0, a, b, now, t;
  scanf("%lld", &n);
  vector<ll> vec[n];
  ll p[n], m[n][2];
  for(i = 0; i < n; ++i) m[i][0] = m[i][1] = 0;
  for(i = 1; i < n; ++i) {
    scanf("%lld%lld", &a, &b);
    vec[--a].push_back(--b);
    vec[b].push_back(a);
  }
  queue<ll> q;
  stack<ll> s;
  q.push(0);
  p[0] = 0;
  while(q.size()) {
    now = q.front(), q.pop();
    s.push(now);
    for(i = 0; i < vec[now].size(); ++i) if(p[now] != vec[now][i]) {
      p[vec[now][i]] = now;
      q.push(vec[now][i]);
    }
  }
  while(s.size()) {
    now = s.top(), s.pop();
    for(i = 0; i < vec[now].size(); ++i) if(p[now] != vec[now][i]) {
      t = vec[now][i];
      if(m[now][0] < m[t][0] + 1) m[now][1] = m[now][0], m[now][0] = m[t][0] + 1;
      else if(m[now][1] < m[t][0] + 1) m[now][1] = m[t][0] + 1;
    }
    if(m[now][0] + m[now][1] + 1 > r) r = m[now][0] + m[now][1] + 1;
  }
  printf("%s", r % 3 == 2 ? "Second" : "First");
  return 0;
}