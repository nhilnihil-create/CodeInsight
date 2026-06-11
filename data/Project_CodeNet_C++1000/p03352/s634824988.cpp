#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int X;
  cin>>X;
  
  long long ans=0;
  
  
  for(int i=1;i<=X;i++){
    for(int j=2;j<=10;j++){
      long long y=pow(i,j);
      if(y<=X){
        ans=max(ans,y);
      }
    }
  }
  
  cout<<ans<<endl;
}