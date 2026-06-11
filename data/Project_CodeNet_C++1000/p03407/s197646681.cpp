#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C;
  cin>>A>>B>>C;
  
  bool ans=false;
  
  if(A+B>=C){
    ans=true;
  }
  
  if(ans){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}