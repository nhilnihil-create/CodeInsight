#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
 
int main(){
  int n, m, a, b, cnt = 0;
  bool is[MAX];
  fill(is, is+MAX, false);
  char s[MAX];
  set<int> p[2][MAX];
  scanf("%d%d%s", &n, &m, s);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &a, &b);
    a--; b--;
    p[s[b] == 'B'][a].insert(b);
    p[s[a] == 'B'][b].insert(a);
  }
  for(int i = 0; i < n; i++){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int j = q.front(); q.pop();
      if(is[j] || !(p[0][j].empty() || p[1][j].empty())) continue;
      int k = p[0][j].empty();
      cnt++;
      is[j] = true;
      for(auto it = p[k][j].begin(); it != p[k][j].end(); it++){
        p[s[j] == 'B'][*it].erase(j);
        q.push(*it);
      }
    }
  }
  puts(cnt == n ? "No" : "Yes");
}