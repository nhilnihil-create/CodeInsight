#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,ans,k,cou;
  cou=0;
  ans=0;
  string str;
  cin>>str;
  a=0;
  b=str.size()-1;
  while(a<str.size()){
    while(a<str.size()){
      if(str.at(a)!='x'){
        break;
      }
      a++;
      k++;
    }
    while(0<=b){
      if(str.at(b)!='x'){
        break;
      }
      k--;
      b--;
    }
    if(a==str.size()){
      break;
    }
    if(str.at(a)!=str.at(b)){
      ans=-1;
      break;
    }
    ans=ans+abs(k);
    a++;
    b--;
    if(cou==0){
      cou=abs(k)+1;
    }
    k=0;
  }
  if(ans==-1){
    cout<<ans;
  }
  else{
 	 cou=cou-1;
 	 ans=(ans+cou)/2;
  	cout<<ans;
  }
}