#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int oddW=0 , evenW=0;
   for(int i=0;i<s.length();i++)
   {
       if( i%2==0 && s[i] =='1')
       {
           evenW++;
       }
       if( i%2==1 && s[i]=='1')
           oddW++;

   }
   int ans =0;
   if( oddW >= evenW )
   {
       ans +=( s.length()/2 - oddW);
       ans+= evenW;
   } else
   {
       if( s.length()%2==0 )
       {
           ans += (s.length()/2 - evenW);
           ans+= oddW;
       } else
       {
           ans += ( s.length()/2 +1 - evenW);
           ans+= oddW;
       }
   }
   cout<<ans;

}