#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int n=s.size();
  int i=0;
  bool ex=false;
  rep2(j,i,n){
    if(s.at(j)=='K'){
      if(j-i<=1){
        ex=true;
      }
      i=j+1;
      break;
    }
    else{
      if(s.at(j)!='A'){
        ex=false;
        break;
      }
    }
  }
  if(ex){
    ex=false;
    rep2(j,i,n){
      if(s.at(j)=='I'){
        if(j-i<=0){
          ex=true;
        }
        i=j+1;
        break;
      }
      else{
        if(s.at(j)!='A'){
          ex=false;
          break;
        }
      }
    }
  }
  if(ex){
    ex=false;
    rep2(j,i,n){
      if(s.at(j)=='H'){
        if(j-i<=0){
          ex=true;
        }
        i=j+1;
        break;
      }
      else{
        if(s.at(j)!='A'){
          ex=false;
          break;
        }
      }
    }
  }
  if(ex){
    ex=false;
    rep2(j,i,n){
      if(s.at(j)=='B'){
        if(j-i<=1){
          ex=true;
        }
        i=j+1;
        break;
      }
      else{
        if(s.at(j)!='A'){
          ex=false;
          break;
        }
      }
    }
  }
  if(ex){
    ex=false;
    rep2(j,i,n){
      if(s.at(j)=='R'){
        if(j-i<=1){
          ex=true;
        }
        i=j+1;
        break;
      }
      else{
        if(s.at(j)!='A'){
          ex=false;
          break;
        }
      }
    }
  }
  if(ex){
    rep2(j,i,n){
      if(s.at(j)!='A'){
        ex=false;
      }
    }
  }
  if(ex){
    if(n-i>1){
      ex=false;
    }
  }
  if(ex){
    cout<<"YES"<<endl;
  }
  
  else{
    cout<<"NO"<<endl;  
  }
  
}


