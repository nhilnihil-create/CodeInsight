#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int D,N;
  cin>>D>>N;
  
  if(D==0&&N==100){
    cout<<101<<endl;
  }
  else if(D==1&&N==100){
    cout<<10100<<endl;
  }
  else if(D==2&&N==100){
    cout<<1010000<<endl;
  }
  else{  
  cout<<pow(100,D)*N<<endl;
  }
}
