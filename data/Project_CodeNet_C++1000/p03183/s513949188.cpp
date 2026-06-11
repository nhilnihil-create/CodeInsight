#include<bits/stdc++.h>
using namespace std;
struct edge{int64_t sum1,w1,s1,v1;};
int64_t dp[1005][20005];
int main(){
  int N;cin>>N;
  map<int64_t,int64_t>Mw;
  map<int64_t,int64_t>Ms;
  map<int64_t,int64_t>Mv;
  vector<pair<int64_t,int64_t>>A(N);
  for(int i=0;i<N;i++){
  int64_t w,s,v;cin>>w>>s>>v;
    Mw[i]=w;
    Ms[i]=s;
    Mv[i]=v;
    pair<int64_t,int64_t>p(w+s,i);
    A.at(i)=p;
  }sort(A.begin(),A.end());
  vector<edge>B(N);
  for(int i=0;i<N;i++){
  int64_t j=A.at(i).second;
    B.at(i).w1=Mw.at(j);
     B.at(i).s1=Ms.at(j);
     B.at(i).v1=Mv.at(j);
  }for(int i=1;i<=N;i++)
    for(int j=1;j<=20004;j++){
    if(B.at(i-1).w1<=j && j<=B.at(i-1).w1+B.at(i-1).s1)
      dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-B.at(i-1).w1]+B.at(i-1).v1));
      else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }cout<<dp[N][20004]<<endl;
  return 0;
}