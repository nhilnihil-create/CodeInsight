#include<bits/stdc++.h>
using namespace std;
vector<pair<int,bool>> v[100000];
int c[100000];
void init(int n){
  fill(c,c+n,-1);c[0] = 0;
}
void dfs(int f){
  int next;
  for(int i=0;i<v[f].size();i++){
    next = v[f][i].first;
    if(c[next]==-1){
      c[next] = c[f]^v[f][i].second;dfs(v[f][i].first);
    }
  }
}
int main(){
  int n,i,x,y,z;scanf("%d",&n);
  init(n);
  for(i=0;i<n-1;i++){
    scanf("%d%d%d",&x,&y,&z);x--;y--;
    v[x].push_back(make_pair(y,z%2));
    v[y].push_back(make_pair(x,z%2));
  }
  dfs(0);
  for(i=0;i<n;i++) printf("%d\n",c[i]);
  return 0;
}