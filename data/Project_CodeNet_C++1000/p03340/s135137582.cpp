#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> p(N);
  vector<vector<int64_t>> q(N+1,vector<int64_t>(20));
  for(int i=0;i<N;i++){
    cin>>p[i];
    for(int j=0;j<20;j++){
      if(p[i]&(1<<j)){
        q[i+1][j]++;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<20;j++){
      q[i+1][j]+=q[i][j];
    }
  }
  int64_t Z=0;
  for(int i=0;i<N;i++){
    int64_t l=-1,r=i;
    while(r-l>1){
      int k=0,D=(l+r)/2;
      for(int j=0;j<20;j++){
        if(q[i+1][j]-q[D][j]>1){
          k=1;
        }
      }
      if(k){
        l=D;
      }
      else{
        r=D;
      }
    }
    Z+=i;
    Z-=l;
  }
  cout<<Z<<endl;
}