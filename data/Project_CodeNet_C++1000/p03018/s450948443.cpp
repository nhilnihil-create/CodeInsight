#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int64_t cnt=0;
  int i=0;

  //aには連続したaの数を持たせる
  int64_t a=0;
  while(i<s.size()){
    if(s[i]=='A'){
        ++i;
        ++a;
    }
    else if(i+1<s.size() && s[i]=='B' && s[i+1]=='C'){
      cnt += a;
      i=i+2;
    }
    else{
      ++i;
      a=0;
    }
  }

  cout<<cnt<<endl;
}

