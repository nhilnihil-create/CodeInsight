#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int S;
  cin>>S;
  
  int L=S/100;
  int R=S%100;
  
  string ans;
  
  
  if(1<=L&&L<=12){
    if(1<=R&&R<=12){
      ans="AMBIGUOUS";
    }
    else{
      ans="MMYY";
    }
  }
  else{
    if(1<=R&&R<=12){
      ans="YYMM";
    }
    else{
      ans="NA";
    }
  }
  
  cout<<ans<<endl;
}