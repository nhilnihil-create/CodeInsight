#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<vector<pair<int,int>>> A(N);
  for(int i=0;i<N-1;i++){
    int u,v,w;
    cin>>u>>v>>w;
    A[u-1].push_back({v-1,w});
    A[v-1].push_back({u-1,w});
  }
  vector<int> B(N,-1);
  B[0]=0;
  queue<int> C;
  C.push(0);
  while(!C.empty()){
    int I=C.front();
    C.pop();
    for(pair<int,int> p:A[I])
      if(B[p.first]==-1){
        B[p.first]=B[I]+p.second;
        C.push(p.first);
      }
  }
  for(int i:B)
    cout<<i%2<<endl;
}