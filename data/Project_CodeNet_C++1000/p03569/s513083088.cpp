#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s;
  t = s;
  reverse(s.begin(),s.end());
  string u="";
  int i=0,j=0;
  bool able=1;
  s+='?';
  t+='?';
  
  while(i<s.size()||j<s.size()){
    if(i==s.size()){
      if(t[j]=='x')  u+='x',j++;
      else able=false; j++;
    }
    else if(j==s.size()){
      if(s[j]=='x')  u+='x',i++;
      else able=false; i++;
    }
      
    else if(s[i]=='x'&&t[j]!='x'){
      u+='x';
      i++;
    }
    else if(s[i]!='x'&&t[j]=='x'){
      u+='x';
      j++;
    }
    else if(s[i]=='x'&&t[j]=='x') u+='x',i++,j++;
    else if(s[i]==t[j]){
      u+=s[i];
      i++,j++;
    }
    else{
      able=false;
      break;
    }
  }
  
  if(able) cout<<u.size()-s.size()<<endl;
  else cout<<-1<<endl;
}