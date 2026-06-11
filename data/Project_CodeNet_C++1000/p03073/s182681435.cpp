#include<bits/stdc++.h>
using namespace std;

int main()

{
   long long a=0,b=0,c,d,e,f,g,h,i,j,k,l,m,n,t;

   string s;

   cin>>s;

   if(s.size()==1) cout<<0<<endl;

   else

   {
       for(i=0;i<s.size();i++)
       {
           if(s[i]=='1' && i%2!=0) a++;

           else if(s[i]=='0' && i%2!=1) a++;
       }

       for(i=0;i<s.size();i++)

       {
           if(s[i]=='1' && i%2!=1) b++;
            else if(s[i]=='0' && i%2!=0) b++;
       }

       c=min(a,b);

       cout<<c<<endl;


   }
}
