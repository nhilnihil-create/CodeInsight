#include<bits/stdc++.h>
using namespace std;
signed main(){
  string s;
  int a=0;
  cin >>s;
  for (int i = 0; i < s.size(); i++){
   if(s[i]=='x'){
     a++;
   }
  }
  if(a>=8){
    cout<<"NO\n";
  }else{
    cout<<"YES\n";
  }
}