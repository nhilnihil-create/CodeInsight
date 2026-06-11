#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

pair<int,int> dfs(Graph &G,int v,int p){
  pair<int,int> ans=make_pair(0,v);
  for(auto nv:G.at(v)){
    if(nv==p){
      continue;
    }
    pair<int,int> p=dfs(G,nv,v);
    ans=max(ans,make_pair(p.first+1,p.second));
  }
  return ans;
}

int main(){
  int N;
  cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  pair<int,int> p=dfs(G,0,-1);
  int v=p.second;
  p=dfs(G,v,-1);
  int n=p.first;
  if((n-1)%3==0){
    cout<<"Second"<<endl;
  }else{
    cout<<"First"<<endl;
  }

}
