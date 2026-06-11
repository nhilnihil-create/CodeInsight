#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int S=0;
  int M=0;
  cin>>N;
  vector<int>vec(N);
  vector<int>v(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  for(int X=0;X<N;X++){
    cin>>v.at(X);
  }
  for(int X=0;X<N;X++){
    S=0;
    for(int Y=0;Y<=X;Y++){
      S+=vec.at(Y);
    }
    for(int Y=X;Y<N;Y++){
      S+=v.at(Y);
    }
    if(M<S){
      M=S;
    }
  }
  cout<<M<<endl;
}