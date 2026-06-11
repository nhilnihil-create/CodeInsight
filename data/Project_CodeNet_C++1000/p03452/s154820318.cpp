#include<bits/stdc++.h>
using namespace std;
int Par[100000],Rank[100000] = {},Weight[100000] = {};
void init(int n){
  for(int i=0;i<n;i++) Par[i] = i;
}
int find(int x){
  if(Par[x]==x) return x;
  int r = find(Par[x]);
  Weight[x] += Weight[Par[x]];
  return Par[x] = r;
}
int weight(int x){
  find(x);
  return Weight[x];
}
int diff(int x,int y){
  return weight(y)-weight(x);
}
void merge(int x,int y,int w){
  w = w+weight(x)-weight(y);
  x = find(x);y = find(y);
  x = find(x);y = find(y);
  if(x==y) return;
  if(Rank[x]<Rank[y]){
    swap(x,y);w = -w;
  }
  if(Rank[x]==Rank[y]) Rank[x]++;
  Par[y] = x;Weight[y] = w;
}
bool same(int x,int y){
  return find(x)==find(y);
}
int main(){
  int n,m,i,l,r,d;scanf("%d%d",&n,&m);
  init(n);
  for(i=0;i<m;i++){
    scanf("%d%d%d",&l,&r,&d);l--;r--;
    if(same(l,r)){
      if(d!=diff(l,r)){
        printf("No\n");return 0;
      }
    } else merge(l,r,d);
  }
  printf("Yes\n");
}