#include<bits/stdc++.h>
#define int long long
using namespace std;
using P=pair<int,int>;
const int INF=1000000000000;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<vector<P>> A(N);
  while(M--){
    int a,b,c;
    cin>>a>>b>>c;
    A[a-1].push_back({b-1,c});
    A[b-1].push_back({a-1,-c});
  }
  vector<int> B(N,INF);
  for(int i=0;i<N;i++){
    if(B[i]!=INF)continue;
    queue<int> Q;
    Q.push(i);
    B[i]=0;
    int mx=0,mn=0;
    while(!Q.empty()){
      int I=Q.front();
      Q.pop();
      mx=max(mx,B[I]);
      mn=min(mn,B[I]);
      for(P p:A[I]){
        if(B[p.first]==INF){
          B[p.first]=B[I]+p.second;
          Q.push(p.first);
        }else if(B[p.first]!=B[I]+p.second){
          puts("No");
          return 0;
        }
      }
    }
    if(mx-mn>1000000000){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}