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
int color[200000]={};

bool dfs(int v,int c){
  color[v]=c;
  for(int i=0;i<G[v].size();++i){
    if(color[G[v][i]]==c) return false;
    if(color[G[v][i]]==0 && !dfs(G[v][i],-c)) return false;
  }
  return true;
}

int main(){
  long long N,M,A,B,ans,tmp;
  cin>>N>>M;
  for(int i=0;i<M;++i){
    cin>>A>>B;
    G[A-1].push_back(B-1);
    G[B-1].push_back(A-1);
  }
  bool divide=dfs(0,1);
  ans=0;
  tmp=0;
  //2部グラフの場合
  if(divide){
    for(int i=0;i<N;++i){
      if(color[i]==1){
        tmp+=1;
      }
    }
    ans=tmp*(N-tmp)-M;
  }
  else{
    ans=N*(N-1)/2-M;
  }
  cout<<ans<<"\n";
return 0;
}
