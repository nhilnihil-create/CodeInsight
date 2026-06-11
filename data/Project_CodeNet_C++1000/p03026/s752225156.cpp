#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> c;
vector<vector<int> > G;
vector<int> ans;
int x = 0;

void dfs(int now, int ago){
 ans[now] = c[x];
 x++;
 for(int i = 0; i < G[now].size(); i++){
   int next = G[now][i];
   if(next == ago) continue;
   dfs(next, now);
 }
}
 
int main(){
  cin >> n;
	G.resize(n);
  for(int i = 0; i < n-1; i++){
    int a,b; scanf("%d%d", &a, &b);
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  int res = 0;
  c.resize(n);
  for(int i = 0; i < n; i++){
    scanf("%d", &c[i]); res += c[i];
  }
  sort(c.begin(),c.end(), greater<int>());
  res -= c[0];
  ans.resize(n);
  dfs(0, -1);
  cout << res << endl;
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
}