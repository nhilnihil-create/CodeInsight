#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main(){
  string s;long long int k;
  cin>>s>>k;
  if(s.at(0)!='1'){cout<<s.at(0);}
  else {
    long long int x=0;
    char y='0';
    rep(i,s.size()){
      if(s.at(i)=='1'){x++;}
      else{y=s.at(i);break;}
    } 
    if(k<=x)cout<<1;
    else{cout<<y;}
  }
}

