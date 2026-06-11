#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000000000

vector<int> parent;
int find(int x){
  int y=parent.at(x);
  if(y!=x){
    y=find(y);
  }
  return parent.at(x)=y;
}

void unite(int a,int b){
  int x=find(a);
  int y=find(b);
  if(x!=y){
    parent.at(x)=y;
  }
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  parent.resize(N);
  for(int i=0;i<N;i++){
    parent.at(i)=i;
  }
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    unite(a,b);
  }

  int ans=0;
  for(int i=0;i<N;i++){
    if(find(p.at(i)-1)==find(i)){
      ans++;
    }
  }
  cout<<ans<<endl;
}
