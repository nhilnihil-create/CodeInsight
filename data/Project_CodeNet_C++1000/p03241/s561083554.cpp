#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M,Z;
  cin>>N>>M;
  for(int i=M/N;i>0;i--){
    if(M%i==0){
      Z=i;
      break;
    }
  }
  cout<<Z<<endl;
}