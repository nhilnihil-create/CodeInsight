#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int s;
  cin>>s;
  
  vector<int> c(1000000);
  c[0]=s;
  for(int i=0;i<1000000;i++){
    if(c[i]%2==0){
      c[i+1]=c[i]/2;
    }
    else if(c[i]%2==1){
      c[i+1]=3*c[i]+1;
    }
  }
  
  for(int i=0;i<=1000000;i++){
    for(int j=i+1;j<=1000000;j++){
      if(c[i]==c[j]){
        cout<<j+1<<endl;
        return 0;
      }
    }
  }
}