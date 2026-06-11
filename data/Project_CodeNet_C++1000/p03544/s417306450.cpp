#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  long long x=2;
  long long y=1;
  long long z=0;
  if(N==1){
    z=1;
  }
  else{
    for(int i=2; i<N+1;i++){
    z=x+y;
    if(i%2==0){
    x=z;
    }
    else{
      y=z;
    }
  }
  }
   cout<<z<<endl;
}