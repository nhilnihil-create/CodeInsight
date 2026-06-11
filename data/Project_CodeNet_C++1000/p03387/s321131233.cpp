#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  bool chk = false;
  int cnt = 0;
  
  cin >> a >> b >> c;
  
  while(chk == false){
    if(a == b && b == c){
      chk = true;
      break;
    }
    
    if(a <= b && a <= c){
      if(a == b){
        a++;
        b++;
        cnt++;
      }else if(a == c){
        a++;
        c++;
        cnt++;
      }else{
        a+=2;
        cnt++;
      }
    }else if(b <= a && b <= c){
      if(b == a){
        b++;
        a++;
        cnt++;
      }else if(b == c){
        b++;
        c++;
        cnt++;
      }else{
        b+=2;
        cnt++;
      }
    }else{
      if(c == a){
        c++;
        a++;
        cnt++;
      }else if(c == b){
        c++;
        b++;
        cnt++;
      }else{
        c+=2;
        cnt++;
      }
    }
  }
  
  cout << cnt;
}
