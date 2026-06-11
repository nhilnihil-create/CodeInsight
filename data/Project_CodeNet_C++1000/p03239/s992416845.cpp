#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,T;
  int M=1001;
  cin>>N>>T;
  vector<vector<int>> vec(N, vector<int>(2));
  for(int X=0;X<N;X++){
    for(int Y=0;Y<2;Y++){
      cin>>vec.at(X).at(Y);
      if (Y==1 && vec.at(X).at(1)<=T){
        if(vec.at(X).at(0)<M){
          M=vec.at(X).at(0);
        }
      }
    }
  }
  if(M==1001){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<M<<endl;
  }
}