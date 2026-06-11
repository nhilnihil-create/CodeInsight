#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  
  scanf("%d %d", &n, &m);
  
  vector<pair<int, int>> events;
  
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    events.emplace_back(r, l);
  }
  
  sort(events.begin(), events.end());
  
  int ans = 0, last_pos = 0;
  for (int i = 0; i < m; i++) {
    if (events[i].second <= last_pos - 1) continue;
    last_pos = events[i].first; ans++;
  }
  
  printf("%d\n", ans);
  
}