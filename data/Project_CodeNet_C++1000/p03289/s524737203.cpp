#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
bool b(){
  string s;cin>>s;
  int n=s.size();
  string s_=s.substr(2,n-3);
  int n_=s_.size();
  string a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  if(s.at(0)!='A'){return false;}
  int c;
  if(count(s_.begin(),s_.end(),'C')==1){
    rep(i,n_){
      if(s_.at(i)=='C'){c=i+2;}     
    }
  }
  if(count(s_.begin(),s_.end(),'C')!=1){return false;}
  
  rep(i,26){
    rep(j,n){
      if(j==0||j==c){continue;}
    if(a.at(i)==s.at(j)){return false;}
    }
  }
  return true;
}

int main() {
  
  if(b()){cout<<"AC"; } 
  else{cout<<"WA";}
}
      