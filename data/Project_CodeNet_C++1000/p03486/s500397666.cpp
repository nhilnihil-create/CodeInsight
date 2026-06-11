#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t; cin>>s>>t;
  vector<char>S(s.size());
  vector<char>T(t.size());
  for(int i=0;i<s.size();i++)S[i]=s.at(i);
  for(int i=0;i<t.size();i++)T[i]=t.at(i);
  sort(S.begin(),S.end());
  sort(T.begin(),T.end());
  reverse(T.begin(),T.end());
  for(int i=s.size()-1;i>=0;i--)s.at(i)=S[i];
  for(int i=0;i<t.size();i--)t.at(i)=T[i];
  cout<<(s<t? "Yes":"No")<<endl;
}