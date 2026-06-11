#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  int n,i;
  map<char,char> ms,mt;
  cin>>s>>t;
  n=s.length();
  for(i=0;i<n;i++){
    if(!ms.count(s.at(i))) ms[s.at(i)]=t.at(i);
    else if(ms[s.at(i)]!=t.at(i)) break;
    if(!mt.count(t.at(i))) mt[t.at(i)]=s.at(i);
    else if(mt[t.at(i)]!=s.at(i)) break;
  }
  if(i<n) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}