#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  bool K=false;
  bool M=false;
  cin>>S;
  for(int X=0;X<S.size();X++){
    for(int Y=X;Y<S.size();Y++){
      string L="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
      int G=0;
      for(int Z=0;Z<S.size();Z++){
        if(Z>=X && Z<=Y){
          continue;
        }
        else{
          L.at(G)=S.at(Z);
          G++;
        }
      }
      if((L.at(0)=='k'&&L.at(1)=='e'&&L.at(2)=='y'&&L.at(3)=='e'&&L.at(4)=='n'&&L.at(5)=='c'&&L.at(6)=='e'&&L.at(7)=='1')){
        K=true;
        M=true;
        break;
      }
    }
    if(M==true){
      break;
    }
  }
  if(K==true){
    cout<<"YES"<<endl;
  }
  else if(S=="keyence"){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
