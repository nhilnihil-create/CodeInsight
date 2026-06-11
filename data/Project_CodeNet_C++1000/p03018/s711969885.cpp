#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  long long ans=0;
  vector<int>count(s.length());
  int t=0;
  for(int i=s.length()-1;i>=0;i--)
  {
    if(i==s.length()-1)count[i]=0;
    else if(s[i]=='B' && s[i+1]=='C')t++;
    else if(s[i]=='A' || (s[i]=='C' && s[i-1]=='B' && i>=2 ))count[i]=t;
    else t=0;
  }
  for(int i=0; i<s.length();i++)
  {
    if(s[i]=='A')ans+=count[i];
  }
  cout<<ans<<endl;
  return 0;
}