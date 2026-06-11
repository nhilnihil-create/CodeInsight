#include<iostream>
#define O return cout<<"NO"<<endl,0
using namespace std;
string s;
main()
{
  cin>>s;
  int id=0;
  if(s[id]=='A')id++;
  if(s[id]=='K')id++;
  else O;
  if(s[id]=='I')id++;
  else O;
  if(s[id]=='H')id++;
  else O;
  if(s[id]=='A')id++;
  if(s[id]=='B')id++;
  else O;
  if(s[id]=='A')id++;
  if(s[id]=='R')id++;
  else O;
  if(s[id]=='A')id++;
  if(id<s.size())O;
  cout<<"YES"<<endl;
}