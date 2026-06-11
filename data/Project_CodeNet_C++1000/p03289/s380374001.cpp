#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int flag=0;
  string s;
  cin >> s;
  rep(i,s.length()){
    if(!i){
      if(s[i]=='A')flag++;
      else break;
    }
    else if((i<s.length()-1)&&(i>1)){
      if(s[i]=='C'){
        if(flag==1)flag++;
        else{
          flag=0;
          break;
        }
      }
      else if(s[i]<='Z'){
        flag=0;
        break;
      }
    }
    else{
      if(s[i]<='Z'){
        flag=0;
        break;
      }
    }
  }
  if(flag==2)cout << "AC" << endl;
  else cout << "WA" << endl;
}