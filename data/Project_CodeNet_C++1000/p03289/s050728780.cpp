#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  bool ex=true;
  if(s[0]!='A'){
    ex=false;
  }
  if(isupper(s[s.size()-1])||isupper(s[1])){
    ex=false;
  }
  if(ex){
    int co=0;
    rep2(i,2,s.size()-1){
      if(s[i]=='C'){
        co++;
      }
    }
    if(co!=1){
      ex=false;
    }
  }
     
  if(ex){
    cout<<"AC"<<endl;
  }
  else{
    cout<<"WA"<<endl;
  }
}