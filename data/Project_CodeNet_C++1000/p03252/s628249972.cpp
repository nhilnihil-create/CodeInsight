#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  string ss,tt;
  map<char,char> ms,mt;
  char cs='a',ct='a';
  for(int i=0;i<s.size();i++){
    if(!ms.count(s.at(i))){
      ms[s.at(i)]=cs;
      cs++;
    }
    if(!mt.count(t.at(i))){
      mt[t.at(i)]=ct;
      ct++;
    }
    ss+=ms.at(s.at(i));
    tt+=mt.at(t.at(i));
  }
  cout<<(ss==tt?"Yes":"No")<<endl;
}