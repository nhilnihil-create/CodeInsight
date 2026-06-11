#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,j,f,x,y,z,ans = 0;scanf("%d%d",&n,&m);
  vector<int> v[n];bool g[n] = {};queue<int> q;
  for(i=0;i<m;i++){
    scanf("%d%d%d",&x,&y,&z);x--;y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(i=0;i<n;i++){
    if(g[i]) continue;
    queue<int>().swap(q);q.push(i);
    while(!q.empty()){
      f = q.front();q.pop();g[f] = 1;
      for(j=0;j<v[f].size();j++){
        if(!g[v[f][j]]) q.push(v[f][j]);
      }
    }
    ans++;
  }
  printf("%d\n",ans);
}