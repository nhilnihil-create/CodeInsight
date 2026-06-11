#include<bits/stdc++.h>
using namespace std;
const int nmax=10005;
int main(){
  int n;cin >> n;
  vector<vector<int>> g(n);
  for(int i=0;i<n-1;i++){
    int a,b;cin >> a >> b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> c(n),ans(n);
  for(int i=0;i<n;i++){
    cin >> c[i];
  }
  sort(c.begin(),c.end(),greater<int>());
  vector<bool> vis(n);
  queue<int> q;
  q.push(0);
  vis[0]=true;
  int cnt=0;
  ans[0]=c[cnt];
  cnt++;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    for(auto x:g[p]){
      if(!vis[x]){
        ans[x]=c[cnt];
        cnt++;
        vis[x]=true;
        q.push(x);
      }
    }
  }
  int sum=0;
  for(int i=1;i<n;i++){
    sum+=c[i];
  }
  cout << sum << endl;
  for(int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << endl;
}