#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>>s;
  string ans="AKIHABARA";
  int i,j;
  bool ok=false;
  for(i=0;i<(1<<4);i++)
  {
    string nam="";
    int counta=0;
    for(j=0;j<ans.size();j++)
    {
      if(ans.at(j)=='A')
      {
        if(i&(1<<counta))nam+=ans.at(j);
        counta++;
      }
      else nam+=ans.at(j);
    }
    if(nam==s)ok=true;
  }
  if(ok)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
