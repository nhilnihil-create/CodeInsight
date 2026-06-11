#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,C;
  int Z=0;
  int U=0;
  cin>>N>>M>>C;
  vector<int>vec(M);
  vector<vector<int>> v(N, vector<int>(M));
  for(int X=0;X<M;X++){
    cin>>vec.at(X);
  }
  for(int X=0;X<N;X++){
    for(int Y=0;Y<M;Y++){
      cin>>v.at(X).at(Y);
    }
  }
  for(int X=0;X<N;X++){
    Z=0;
    for(int Y=0;Y<M;Y++){
      Z+=v.at(X).at(Y)*vec.at(Y);
      if(Y+1==M && Z+C>0){
        U++;
      }
    }
  }
  cout<<U<<endl;
}