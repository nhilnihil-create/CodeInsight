#include<bits/stdc++.h>
using namespace std;



int main(){
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for(int i=0;i<n-1;++i){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> c(n);
  for(int i=0;i<n;++i) cin >> c[i];

  sort(c.rbegin(),c.rend());
  long long ans=0;
  queue<int> q;
  vector<int> d(n,-1);
  q.push(0);
  int index=0;
  while(!q.empty()){
    int v=q.front();
    q.pop();
    d[v]=c[index];
    index++;
    ans+=d[v];
    for(auto nv : g[v]){
      if(d[nv]==-1) q.push(nv);
    }
  }
  ans-=c[0];
  cout << ans << endl;
  for(int i=0;i<n;++i){
    if(i!=n-1) cout << d[i] << " ";
    else cout << d[i] << endl;
  }
  return 0;
}
