#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  int ans=0;
  
  
  if(N<105){
    ans=0;
  }
  else if(N<135){
    ans=1;
  }
  else if(N<165){
    ans=2;
  }
  else if(N<189){
    ans=3;
  }
  else if(N<195){
    ans=4;
  }
  else{
    ans=5;
  }
  
  cout<<ans<<endl;
}