#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<tuple<int64_t,int64_t,int64_t,int64_t>>> p(8,vector<tuple<int64_t,int64_t,int64_t,int64_t>>(N));
  vector<tuple<int64_t,int64_t,int64_t,int64_t>> q(8);
  for(int i=0;i<N;i++){
    int64_t a,b,c;
    cin>>a>>b>>c;
    for(int j=0;j<8;j++){
      int64_t A=a,B=b,C=c;
      if(j&(1<<0)){
        A*=-1;
      }
      if(j&(1<<1)){
        B*=-1;
      }
      if(j&(1<<2)){
        C*=-1;
      }
      p[j][i]=make_tuple(A+B+C,A,B,C);
    }
  }
  int64_t Z=0;
  for(int i=0;i<8;i++){
    sort(p[i].begin(),p[i].end());
    reverse(p[i].begin(),p[i].end());
    for(int j=0;j<M;j++){
      int64_t z,w,e,r;
      int64_t a,s,d,f;
      tie(z,w,e,r)=q[i];
      tie(a,s,d,f)=p[i][j];
      z+=a,w+=s,e+=d,r+=f;
      q[i]=make_tuple(z,w,e,r);
    }
    int64_t a,b,c,d;
    tie(a,b,c,d)=q[i];
    Z=max(Z,abs(b)+abs(c)+abs(d));
  }
  cout<<Z<<endl;       
}