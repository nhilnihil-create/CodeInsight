#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<int>>p(N+1,vector<int>(N+1));
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    p.at(a).at(b)++;
  }
  vector<vector<int>>q(N+1,vector<int>(N+1));
  for(int i=1;i<=N;i++){
    for(int j=i;j<=N;j++){
      q.at(i).at(j)=q.at(i).at(j-1)+p.at(i).at(j);
    }
  }
  vector<vector<int>>r(N+1,vector<int>(N+1));
  for(int j=1;j<=N;j++){
    r.at(j).at(j)=q.at(j).at(j);
    for(int i=j-1;i>0;i--){
      r.at(i).at(j)=r.at(i+1).at(j)+q.at(i).at(j);
    }
  }
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    cout<<r.at(a).at(b)<<endl;
  }
}