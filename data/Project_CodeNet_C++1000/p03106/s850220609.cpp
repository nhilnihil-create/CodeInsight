#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,K;
  cin>>A>>B>>K;
  
  int check=0;
  
  
  for(int i=min(A,B);i>0;i--){
    if(A%i==0&&B%i==0){
      check++;
    }
    if(check==K){
      cout<<i<<endl;
      break;
    }
  }
}