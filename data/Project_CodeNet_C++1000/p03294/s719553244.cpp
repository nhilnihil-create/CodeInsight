#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int M=0;
  long long L=0;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    L+=vec.at(X);
    if(M!=0){
      M=lcm(vec.at(X),M);
    }
    else{
      M=vec.at(X);
    }
  }
  cout<<L-N<<endl;
}