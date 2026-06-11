#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  bool test=true;
  if(s[0]!='A'){
    test=false;
  }
  int count=0;
  for(int i=1;i<s.size();i++){
    if(isupper(s[i])){
      count++;
      if(i==1||i==s.size()-1||s[i]!='C'){
        test=false;
      }
    }
  }
  if(count!=1){
    test=false;
  }
  if(test){
    cout<<"AC"<< endl;
  }
  else{
    cout<<"WA"<< endl;
  }
}
    
