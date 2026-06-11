#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

vector<int> G[200000];
int tree[200000]={};

void dfs1(int x){
  for(int j=0;j<G[x].size();j++){
    if(tree[G[x][j]]<0){
    tree[G[x][j]]=tree[x]+1;
    dfs1(G[x][j]);}
  }
  return;
}


int main(){
int N;
cin>>N;
int a,b;
for(int i=0;i<N;++i){
  tree[i]=(-1);
  if(i<N-1){
  cin>>a>>b;
  a--;
  b--;
  G[a].push_back(b);
  G[b].push_back(a);}
}

tree[0]=0;
dfs1(0);

int x,y,xd,yd;
x=0;
xd=-1;
y=0;
yd=-1;
for(int i=0;i<N;++i){
  if(xd<tree[i]){
    xd=tree[i];
    x=i;
  }
  tree[i]=(-1);
}

tree[x]=0;
dfs1(x);

for(int i=0;i<N;++i){
  if(yd<tree[i]){
    yd=tree[i];
    y=i;
  }
}
if(yd%3==1){
  cout<<"Second"<<"\n";
}
else{
  cout<<"First"<<"\n";
}
return 0;
}