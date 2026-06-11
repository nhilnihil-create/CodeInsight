#include <bits/stdc++.h>
#define ll long long
using namespace std;

int root[100010]; //root[i]=i's parent
ll element[100010];

void init(int n){
  for(int i=0;i<n;i++) root[i]=i,element[i]=1;
}//reset
int find(int x){
  if(root[x]==x){
    return x;
  }
  else{
    return root[x]=find(root[x]);
  }
}//search x's parent
bool same(int x,int y){
  return find(x)==find(y);
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  root[x]=y;
  element[y]+=element[x];
}//x->y

int main(){
  ll n,m;
  cin>>n>>m;
  init(n);
  int edge[m][2];
  for(int i=m-1;i>=0;i--){
    cin>>edge[i][0]>>edge[i][1];
    edge[i][0]--;
    edge[i][1]--;
  }
  ll ans[m];
  ans[0]=0;
  for(int i=0;i<m-1;i++){
    if(same(edge[i][0],edge[i][1])==true){
      ans[i+1]=ans[i];
      /*for(int j=0;j<n;j++){
        cout<<root[j]<<" ";
      }
      cout<<ans[i+1]<<" ";
      cout<<endl;*/
      continue;
    }
    ans[i+1]=ans[i]+element[find(edge[i][0])]*element[find(edge[i][1])];
    unite(edge[i][0],edge[i][1]);
    /*for(int j=0;j<n;j++){
      cout<<root[j]<<" ";
    }
    cout<<ans[i+1]<<" ";
    cout<<endl;*/
  }
  for(int i=m-1;i>=0;i--){
    cout<<(n*(n-1))/2-ans[i]<<endl;
  }
}