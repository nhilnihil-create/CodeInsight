#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;
  if(S.size()==26){
    if(S=="zyxwvutsrqponmlkjihgfedcba"){
      cout<<-1<<endl;
    }
    else{
      int L=1;
      for(int X=24;X>=0;X--){
        if(S[X]>S[X+1]){
          L++;
        }
        else{
          break;
        }
      }
      for(int X=0;X<25-L;X++){
        cout<<S[X];
      }
      for(char X=S[25-L];X<='z';X++){
        bool H=true;
        for(int Y=0;Y<26-L;Y++){
          if(S[Y]==X){
            H=false;
          }
        }
        if(H){
          cout<<X<<endl;
          break;
        }
      }
    }
  }
  else{
    cout<<S;
    for(char X='a';X<='z';X++){
      bool H=true;
      for(int Y=0;Y<S.size();Y++){
        if(S[Y]==X){
          H=false;
        }
      }
      if(H){
        cout<<X<<endl;
        break;
      }
    }
  }
}