#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin >> n >> m;
  vector<int> g[100005];
  vector<int> h(n),ans(n);
  for(int i=0;i<n+m-1;i++){
    int a,b;cin >> a >> b;
    a--,b--;
    g[a].push_back(b);
    h[b]++;
  }
  int rt=-1;
  for(int i=0;i<n;i++){
    if(h[i]==0){
      rt=i;
    }
  }
  queue<int> q;
  q.push(rt);
  ans[rt]=0;
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(auto x:g[v]){
      h[x]--;
      if(h[x]==0){
        ans[x]=v+1;
        q.push(x);
      }
    }
  }
  for(auto x:ans){
    cout << x << endl;
  }
}