#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
 
int main(){
  int n, m, a, b, c[MAX][2], used[MAX];
  vector<int> v[MAX][2];
  char s[MAX];
  scanf("%d%d", &n, &m);
  fill(c[1], c[n+1], 0);
  fill(used+1, used+n+1, false);
  scanf("%s", s+1);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &a, &b);
    v[a][s[b] - 'A'].push_back(b);
    v[b][s[a] - 'A'].push_back(a);
    c[a][s[b] - 'A']++;
    c[b][s[a] - 'A']++;
  }
  for(int i = 1; i <= n; i++){
    if(used[i] || (c[i][0] && c[i][1])) continue;
    deque<int> d = {i};
    while(!d.empty()){
      int t = d.front(); d.pop_front();
      if(used[t]) continue;
      int k = (c[t][0] == 0);
      for(auto it : v[t][k]){
        c[it][s[t] == 'B']--;
        if(!c[it][s[t] == 'B']) d.push_front(it);
      }
      used[t] = true;
    }
  }
  bool ans = false;
  for(int i = 1; i <= n; i++){
    if(c[i][0] && c[i][1]) ans = true;
  }
  puts(ans ? "Yes" : "No");
  
}