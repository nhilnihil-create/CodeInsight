#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,x;
  cin>>x>>N;
  vector<vector<int>> p(N+1,vector<int>(N+1,1000));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>p.at(i+1).at(j+1);
    }
  }
  int A=250000000;
  vector<int>a(N);
  vector<int>b(N);
  vector<int>c(N);
  for(int i=0;i<x;i++){
    for(int j=0;j<x;j++){
      int z;
      cin>>z;
      if((i+j)%3==0){
        for(int k=0;k<N;k++){
          a.at(k)+=p.at(z).at(k+1);
        }
      }
      else if((i+j)%3==1){
        for(int k=0;k<N;k++){
          b.at(k)+=p.at(z).at(k+1);
        }
      }
      else if((i+j)%3==2){
        for(int k=0;k<N;k++){
          c.at(k)+=p.at(z).at(k+1);
        }
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int k=i+1;k<N;k++){
      for(int j=k+1;j<N;j++){
        A=min(A,a.at(i)+b.at(k)+c.at(j));
        A=min(A,a.at(i)+b.at(j)+c.at(k));
        A=min(A,a.at(j)+b.at(i)+c.at(k));
        A=min(A,a.at(j)+b.at(k)+c.at(i));
        A=min(A,a.at(k)+b.at(i)+c.at(j));
        A=min(A,a.at(k)+b.at(j)+c.at(i));
      }
    }
  }
  
  cout<<A<<endl;
}