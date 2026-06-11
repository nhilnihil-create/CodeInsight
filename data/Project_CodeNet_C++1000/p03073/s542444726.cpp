#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,n,tiles=0;
    string s;
    cin>>s;
   if(s[0]=='0')
   {
       for(i=0;i<s.size();i++)
       {
           if(i%2==0)
           {
               if(s[i]!='0')
                tiles++;
           }
           else if(i%2!=0)
                if(s[i]!='1')
                tiles++;
       }
   }
   else if(s[0]=='1')
   {
       for(i=0;i<s.size();i++)
       {
           if(i%2==0)
           {
               if(s[i]!='1')
                tiles++;
           }
           else if(i%2!=0)
                if(s[i]!='0')
                tiles++;
       }
   }
   cout<<tiles;

}
