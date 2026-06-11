#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int64_t N=S.size(),A=0,Z=0,i=1;
  while(i<N){
    if(S.at(i-1)=='A'){
    A++;
  }
    else if(S.at(i)=='C'&&S.at(i-1)=='B'){
      Z+=A;
      i++;
    }
    else{
      A=0;
  }
    i++;
  }
  cout<<Z<<endl;
}