#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s , t;
   cin>>s>>t;
   bool equal = false;
   for(int i=0;i<s.length();i++)
   {
       if( s== t)
       {
           equal = true;
           break;
       }
       s = s.back() + s.substr(0,s.length()-1 );

   }
   if( equal)
       cout<<"Yes";
   else cout<<"No";
}