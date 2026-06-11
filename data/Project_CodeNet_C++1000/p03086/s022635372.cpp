#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int ans=0;
  vector<char> data={'A','C','G','T'};
  
  for(int i=0;i<s.size();i++){
    for(int j=1;i+j<=s.size();j++){
      string ss=s.substr(i,j);
      for(int k=0;k<ss.size();k++){
        for(char d:data){
          if(ss.at(k)!=data.at(0)&&ss.at(k)!=data.at(1)&&ss.at(k)!=data.at(2)&&ss.at(k)!=data.at(3)){
            goto SKIP;
          }
        }
      }
      if(ss.size()>ans){
        ans=ss.size();
      }
      SKIP:;
    }
  }
  
  cout << ans;
}
