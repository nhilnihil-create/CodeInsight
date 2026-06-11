#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct edge{
  int  to;
  int cost;
  edge(int t,int w) : to(t),cost(w){}
};
int main(){
  long long int i,n,m,a,b,ans[100010],x,k=0,check=0,black=0,white=0;
  stack<int> s;
  scanf("%lld %lld\n",&n,&m);
  vector<vector<edge>> g(n+10);
  for(i=0;i<m;i++){
    scanf("%lld %lld\n",&a,&b);
    g[a].push_back(edge(b,1));
    g[b].push_back(edge(a,1));
  }
  for(i=1;i<=n;i++){
    ans[i]=0;
  }
  s.push(1),ans[1]=-1;
  while(!s.empty()){
    x=s.top();
    s.pop();
    for(i=0;i<g[x].size();i++){
      if(ans[g[x][i].to]==0){
        ans[g[x][i].to]=-ans[x];
        s.push(g[x][i].to);
      }
      else if(ans[g[x][i].to]==ans[x]){
        check=1;
        break;
      }
    }
    if(check==1){
      break;
    }
  }
  if(check==1){
    printf("%lld\n",n*(n-1)/2-m);
  }
  else{
    for(i=1;i<=n;i++){
      if(ans[i]==1){
        black++;
      }
      else{
        white++;
      }
    }
    printf("%lld\n",black*white-m);
  }
  return 0;
}