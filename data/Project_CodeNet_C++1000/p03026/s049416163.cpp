#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  vector<vector<int>> G(N,vector<int>(0));
  vector<int> c(N);
  long long sum = 0;
  for(int i = 0;i < N-1;i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  } 

  for(int i = 0;i < N;i++) cin >> c.at(i);
  sort(c.rbegin(),c.rend());

  queue<int> Q;
  vector<bool> seen(N,false);
  vector<int> ans(N);
  ans[0] = c[0];
  Q.push(0);
  seen[0] = true;
  int now = 1;
  
  while(!Q.empty()) {
    int q = Q.front();
    Q.pop();
    for(int v:G[q]) {
      if(seen[v]) continue;
      sum += c[now];
      ans[v] = c[now];
      now++;
      Q.push(v);
      seen[v] = true;
    }
  }

  cout << sum << endl;
  for(int i = 0;i < N;i++) cout << ans[i] << " ";
  cout << endl;
  
}
