#include<bits/stdc++.h>
using namespace std;
string s,t,a;
bool c=true,h=true;
int g;
int main()
{
  cin>>s;
  cin>>t;
  if(s.size()<t.size())
   {
     cout<<"UNRESTORABLE"<<endl;
     return 0;
   }
  for(int i=0;i<=s.size()-t.size();i++)
     {
       h=true;
       for(int j=0;j<t.size();j++)
         if(s[i+j]!=t[j])
          {
            if(s[i+j]=='?')
             continue;
            h=false;
            break;
          }
       if(h)
        {
          c=false;
          g=i;
        }
     }
  if(c)
   {
     cout<<"UNRESTORABLE"<<endl;
     return 0;
   }
  for(int i=0;i<s.size();i++)
    {
      if(i==g)
       {
         cout<<t;
         i+=t.size()-1;
       }
      else if(s[i]=='?')
            cout<<"a";
      else
         cout<<s[i];
    }
  cout<<endl;
  return 0;
}