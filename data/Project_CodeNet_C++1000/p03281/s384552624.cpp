#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  int M=0;
  vector<int>V{105,135,165,189,195};
  for(int X=0;X<5;X++){
    if(N<V[X]){
      break;
    }
    else{
      M++;
    }
  }
  cout<<M<<endl;
}