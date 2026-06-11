#include<bits/stdc++.h>
using namespace std;

int main()

{
   long long a=0,b=0,c=0,d,e,f,g,h,i,j,k,l,m,n,t;

       cin>>n;

       long long ar[n]; long long bar[n];

       for(i=0;i<n;i++)
       {
           cin>>ar[i];
       }
         for(i=0;i<n;i++)
       {
           cin>>bar[i];
       }
       for(i=0;i<n;i++)
           {if(ar[i]>bar[i])
           {
               c=ar[i]-bar[i];
               a=a+c;
           }
           }


       cout<<a<<endl;
   }



