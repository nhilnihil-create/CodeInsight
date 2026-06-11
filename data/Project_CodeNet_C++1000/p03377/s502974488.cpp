#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,X;cin>>A>>B>>X;
  
  if(A>X){
    cout<<"NO"<<endl;
  }
  else if(A<=X&&A+B>=X){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
    