#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  vector<char> vs(s.size()),vt(t.size());
  for(int i=0;i<s.size();i++)vs.at(i)=s.at(i);
  for(int i=0;i<t.size();i++)vt.at(i)=t.at(i);
  
  sort(vs.begin(),vs.end());
  
  sort(vt.begin(),vt.end());
  reverse(vt.begin(),vt.end());
  
  if(vs>=vt)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}