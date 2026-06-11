#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<vector<int>> p(N,vector<int>(10));
  for(int i=0;i<N;i++){
    for(int j=0;j<10;j++){
      cin>>p[i][j];
    }
  }
  vector<vector<int>> q(N,vector<int>(11));
  for(int i=0;i<N;i++){
    for(int j=0;j<11;j++){
      cin>>q[i][j];
    }
  }
  vector<int> r(N);
  vector<int> em(N);
  int Z=-2001924167,A;
  for(int i=1;i<1024;i++){
    r=em;
    A=0;
    for(int j=0;j<10;j++){
      if(i&(1<<j)){
        for(int k=0;k<N;k++){
          r[k]+=p[k][j];
        }
      }
    }
    for(int k=0;k<N;k++){
      A+=q[k][r[k]];
    }
    Z=max(A,Z);
  }
  cout<<Z<<endl;
}