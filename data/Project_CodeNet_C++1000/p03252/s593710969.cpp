#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string s,t;
  cin >> s>>t;
  int n=s.size();
  map<char,char>memo,memo2;
  bool ex=true;
  rep(i,n){
    if(memo.count(s.at(i))){
      if(memo[s.at(i)]!=t.at(i)){
        ex=false;
        break;
      }
    }
    else{
      memo[s.at(i)]=t.at(i);
      
    }
  }
  rep(i,n){
    if(memo2.count(t.at(i))){
      if(memo2[t.at(i)]!=s.at(i)){
        ex=false;
        break;
      }
    }
    else{
      memo2[t.at(i)]=s.at(i);
      
    }
  } 
   
  if(ex){
      cout<<"Yes"<<endl;
  }
  else{    
    cout<<"No"<<endl;
  }
}