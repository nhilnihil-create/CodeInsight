#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;

  if(s[0]!='A'){
    cout << "WA" << endl;
    return 0;
  }
  
  int x=0,y;
  for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C') {
      x++;
      y=i;
    }
  }
  if(x!=1) {
    cout << "WA" << endl;
    return 0;
  }
  
  for(int i=1;i<s.size();i++){
    if(i==y) continue;
    else if((int)s[i]<97 || 122<(int)s[i]){
      cout << "WA" << endl;
      return 0;
    }
  }
  
  cout << "AC" << endl;
  return 0; 
}