#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<n;i++)
#define test(a) cout << "*" << a << endl;
int main(){
  string s;
  bool existAC = false;
  int i;
  int existC=false;
  int placeC;
  
  cin >> s;
  
  if(s[0]=='A'){
    for(i=2;i<s.size()-1;i++){
      if(s[i]=='C'){
        if(existC==true){ 
          existC=false;
          break;  
        }
        placeC=i;   
        existC = true;
      }
    }
    if(existC==true){
      rep1(i,s.size()){
        if(i==placeC){
          continue;   
        }
        if('a'<=s[i] && s[i]<='z'){
          if(i==s.size()-1){
            existAC = true;
          }
        }
        else{
          break; 
        }
      }
    }
  }
    
    if(existAC==true)
      cout << "AC" << endl;
    else
      cout << "WA" << endl;
  
  
}