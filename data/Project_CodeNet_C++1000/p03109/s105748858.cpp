#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool a=false;//false:TBD//
  string M="mm",D="dd";
  
  for(int i=0;i<2;i++){
    M.at(i)=S.at(i+5);
  }
  for(int i=0;i<2;i++){
    D.at(i)=S.at(i+8);
  }
  
  if(M=="01" || M== "02" || M=="03" || M=="04"){
    a=true;
  }
  if(a){
    cout << "Heisei" << endl;
  }
  else{
    cout << "TBD" << endl;
  }
}