#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  
  for(int i=0;i<s.size();i++){
    string u="";
    for(int j=0;j<s.size();j++){
      u+=s.at((i+j+1)%s.size());
    }
    if(u==t){
      cout << "Yes" << endl;
      break;
    }
    else if(i==s.size()-1){
      cout << "No" << endl;
    }
  }
}