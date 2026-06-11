#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s;
  t=s;
  int a=0,b=1;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='0'&&s[i+1]=='0'){ 
      s[i+1]='1';
      a++;
    }
    else if(s[i]=='1'&&s[i+1]=='1'){
      s[i+1]='0';
      a++;
    }
  }
  
  if(s[0]=='0') t[0]='1';
  else t[0]='0';
  
  for(int i=0;i<s.size()-1;i++){
    if(t[i]=='0'&&t[i+1]=='0'){ 
      t[i+1]='1';
      b++;
    }
    else if(t[i]=='1'&&t[i+1]=='1'){
      t[i+1]='0';
      b++;
    }
  }
  
  cout << min(a,b) << endl;
  
  
}
