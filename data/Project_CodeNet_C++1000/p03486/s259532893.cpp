#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  char min_s=s[0];
  char max_t=t[0];
  for(int i=0; i<s.size(); i++){
      if(s[i]<min_s){
        min_s=s[i];
      }
  }
  for(int j=0; j<t.size(); j++){
      if(t[j]>max_t){
        max_t=t[j];
      }
  }
  if(min_s<max_t){
    cout << "Yes" << endl;
  }
  else{
    bool c=true;
    for(int i=0; i<s.size(); i++){
      if(s[i]!=t[i]){
        c=false;
      }
    }
    if(c && s.size()<t.size()){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  
  
}