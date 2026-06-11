#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int64_t A=2, B=1;
  for(int i=0;i<N-1;i++){
    int64_t C=B;
    B+=A;
    A=C;
  }
  cout<<B;
}