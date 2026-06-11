#include<bits/stdc++.h>
using namespace std; 
int main()
{
  int i,sum=1<<30;
  string ch;	
  cin>>ch;
  for(i=1;i<ch.length();i++)
    if(ch[i]!=ch[i-1]) 
      sum=min(sum,max(i,int(ch.length())-i)); 
  cout<<min(sum,int(ch.length()))<<endl; 
  return 0;
}