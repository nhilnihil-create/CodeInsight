#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,s1,s2,s3[55],s4="~";
  int ba=0;
  cin>>s>>s1;
  s2=s;
  if(s.size()<s1.size())
   {
    cout<<"UNRESTORABLE";
    return 0; 
   }
  for(int t=0;t<=s.size()-s1.size();t++)
    {
      string s0;
      s0=s.substr(t,s1.size());
      if(s0==s1)
        {
           for(int i=0;i<s.size();i++)
            {
              if(s[i]=='?')
             {
              s[i]='a';
             }
            }
            cout<<s;
            return 0;
        } 
	}
        
   for(int t=s.size()-s1.size();t>=0;t--)
      { 
        bool ok=1;
        for(int i=t;i<t+s1.size();i++)
           {
            if(s[i]==s1[i-t]||s[i]=='?')
              {
               s[i]=s1[i-t];
              }   
            else
              {
               ok=0;
               s=s2;
               break;
              } 
            }
            if(ok)
              { 
                for(int i=0;i<s.size();i++)
                   {
                     if(s[i]=='?')
                       { 
                        s[i]='a';
                       } 
                    } 
                s3[ba]=s;
                s4=min(s4,s);
                ba++;
              } 
           } 
        if(s4=="~")
          {
            cout<<"UNRESTORABLE";
          } 
        else
          {
            cout<<s4;
          } 
        return 0;
}
