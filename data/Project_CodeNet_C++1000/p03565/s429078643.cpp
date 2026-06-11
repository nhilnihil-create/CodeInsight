#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check( string s , string t)
{
    for( int i=0;i<s.length() ;i++)
    {
        if( s[i] != t[i] && s[i] != '?' )
            return false;
    }
    return true;
}
int main()
{
   string s,t;
   cin>>s>>t;

   bool found = false;
   for( int  i=s.length() - t.length();i>= 0 ;i--)
   {
       string temp = s.substr(i , t.length() );
        if( check(temp , t  ) )
        {
            for(int j=0;j<t.length() ;j++)
            {
                s[j+i] = t[j];
            }
            found = true;
            break;
        }
   }
   if( found )
   {
       for(unsigned int i=0;i<s.length() ;i++)
       {
           if( s[i] =='?')
               s[i] = 'a';
       }
       cout<<s;
   } else cout<<"UNRESTORABLE";
}