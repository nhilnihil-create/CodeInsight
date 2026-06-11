#include <bits/stdc++.h>
#define ll long long
using namespace std;

int root[100010]; //root[i]=i's parent
int element[100010]; //element[i]=i's group's element
//element[find(i)] is better
 
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
}//x"->"y

int main(){
  int n,m;
  cin>>n>>m;
  init(n);
  int x,y,z;
  for(int i=0;i<m;i++){
    cin>>x>>y>>z;
    x--;
    y--;
    unite(x,y);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(element[find(i)]>0){
      ans++;
      element[find(i)]=0;
    }
  }
  cout<<ans<<endl;
}