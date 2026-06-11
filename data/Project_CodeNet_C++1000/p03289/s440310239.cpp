#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  
  bool juge = true;
  
  string first = s.substr(0,1);
  if(first!="A"){
    juge = false;
   }
  
  int cnt=0;
  for(int i=2;i<s.length()-1;i++)
  {
   

    if(s[i]=='C'){
      cnt++;
    }
  }
  
  if(cnt !=1)
  {
      juge = false;
  }
  
  for(int i=0;i<s.length();i++)
  {
       string v = s.substr(i,1);
    
      if(v!="A"&&v!="C"&&v<"Z")
      {
          juge = false;
      }
    
  }
  
  
  if(juge)
  {
       cout<<"AC"<<endl;
  }
  else
  {
       cout<<"WA"<<endl;
  }
  
  return 0;
}
  
  
  
