#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i=0;i<16;i++){
    string a="",b="",c="",d="";
    if(i&1){
      a='A';
    }
    if(i>>1&1){
      b='A';
    }
    if(i>>2&1){
      c='A';
    }
    if(i>>3&1){
      d='A';
    }
    string t=a+"KIH"+b+"B"+c+"R"+d;
    if(t==s){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}