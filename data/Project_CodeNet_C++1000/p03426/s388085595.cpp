#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t H,W,D;
  cin>>H>>W>>D;
  map<int64_t,pair<int64_t,int64_t>>M;
  for(int64_t i=0;i<H;i++)
    for(int64_t j=0;j<W;j++){
    int64_t a;cin>>a;
      pair<int64_t,int64_t>p(i,j);
      M[a]=p;
     }map<int64_t,int64_t>m;
  for(int64_t i=1;i<=D;i++)
    m[i]=0;
  for(int64_t i=D+1;i<=H*W;i++){
  int64_t I1=M.at(i).first;int64_t J1=M.at(i).second;
    int64_t I2=M.at(i-D).first;int64_t J2=M.at(i-D).second;
    m[i]=m[i-D]+abs(I1-I2)+abs(J1-J2);
  }int Q; cin>>Q;
  for(int i=0;i<Q;i++){
  int64_t L,R; cin>>L>>R;
    cout<<m.at(R)-m.at(L)<<endl;
  }
  return 0;
}