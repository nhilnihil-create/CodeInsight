#include <bits/stdc++.h>
using namespace std;

int main(){
  int S;
  cin>>S;
  string ans;
  if(S/100>=1&&S/100<=12&&S%100>=1&&S%100<=12){
    ans = "AMBIGUOUS";
  }
  else if(S/100>=1&&S/100<=12){
    ans = "MMYY";
  }
  else if(S%100>=1&&S%100<=12){
    ans = "YYMM";
  }
  else{
    ans = "NA";
  }
  cout<<ans<<endl;
}