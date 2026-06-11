#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
  int N;
  cin>>N;
  vector<vector<pair<int,int>>> A(N);
  for(int i=1;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    A[a-1].push_back({b-1,c});
    A[b-1].push_back({a-1,c});
  }
  vector<int> B(N,-1);
  queue<int> Q;
  B[0]=0;
  Q.push(0);
  while(!Q.empty()){
    int I=Q.front();
    Q.pop();
    for(pair<int,int> p:A[I])
      if(B[p.first]==-1){
        B[p.first]=(B[I]+p.second)%2;
        Q.push(p.first);
      }
  }
  for(int i=0;i<N;i++)cout<<B[i]<<endl;
}