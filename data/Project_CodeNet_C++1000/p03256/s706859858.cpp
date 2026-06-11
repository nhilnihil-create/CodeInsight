#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
  int i, n, m, a, b;
  scanf("%d%d", &n, &m);
  queue<int> q, qt;
  bool flg[n];
  for(i = 0; i < n; ++i) flg[i] = true;
  char s[n + 10];
  scanf("%s", s);
  int an[n], bn[n];
  vector<int> vec[n];
  for(i = 0; i < n; ++i) an[i] = bn[i] = 0;
  for(i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--, b--;
    vec[a].push_back(b);
    if(a != b) vec[b].push_back(a);
    if(s[a] == 'A') an[b]++;
    else bn[b]++;
    if(a != b) {
      if(s[b] == 'A') an[a]++;
      else bn[a]++;
    }
  }
  for(i = 0; i < n; ++i) if(!an[i] || !bn[i]) q.push(i), flg[i] = false;
  while(!q.empty()) {
    while(!q.empty()) {
      int t = q.front();
      q.pop();
      for(i = 0; i < vec[t].size(); ++i) if(flg[vec[t][i]]) {
         if(s[t] == 'A') an[vec[t][i]]--;
         else bn[vec[t][i]]--;
         if(!an[vec[t][i]] || !bn[vec[t][i]]) flg[vec[t][i]] = false, qt.push(vec[t][i]);
      }
    }
    while(!qt.empty()) q.push(qt.front()), qt.pop();
  }
  for(i = 0; i < n; ++i) if(flg[i]) {
    printf("Yes");
    return 0;
  }
  printf("No");
  return 0;
}