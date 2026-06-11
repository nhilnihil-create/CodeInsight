#include <bits/stdc++.h>
using namespace std;
 
const int INF=250000;
int main(){
  int N,C;
  cin>>N>>C;
  vector<int> s(N),t(N),c(N);
  for(int i=0;i<N;++i){
    cin>>s[i]>>t[i]>>c[i];
    s[i] *= 2;
    t[i] *= 2;
  }
 
  vector<vector<int>> sum(C+1,vector<int>(INF));
  for(int i=0;i<N;++i){
    ++sum[c[i]][s[i]-1];
    --sum[c[i]][t[i]+1];
  }
 
  for(int i=1;i<=C;++i){
    for(int j=1;j<INF;++j){
      sum[i][j] += sum[i][j-1];
    }
  }
 
  int cnt=0;
  for(int i=0;i<INF;++i){
    int subcnt=0;
    for(int j=1;j<=C;++j){
      if(sum[j][i]>0) ++subcnt;
    }
    cnt=max(cnt,subcnt);
  }
  cout<<cnt<<endl;
}