#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 998244353
#define INF 1000000000

ll one;
ll zero;
bool nibu;

void dfs(Graph &G,int v,vector<int> &color){
  for(auto nv:G.at(v)){
    if(color.at(nv)==-1){
      color.at(nv)=1-color.at(v);
      if(color.at(nv)==1){
        one++;
      }else{
        zero++;
      }
      dfs(G,nv,color);
    }else{
      if(1-color.at(v)!=color.at(nv)){
        nibu=true;
      }
    }
  }
}

int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
    int A,B;
    cin>>A>>B;
    A--;B--;
    G.at(A).push_back(B);
    G.at(B).push_back(A);
  }

  ll ans=0;
  vector<int> color(N,-1);
  for(int i=0;i<N;i++){
    if(color.at(i)!=-1){
      continue;
    }
    color.at(i)=0;
    zero=1;
    one=0;
    nibu=false;
    dfs(G,i,color);
    if(nibu){
      ans+=(zero+one)*(zero+one-1)/2;
    }else{
      ans+=one*zero;
    }
  }

  ans-=(ll)M;

  cout<<ans<<endl;
}
