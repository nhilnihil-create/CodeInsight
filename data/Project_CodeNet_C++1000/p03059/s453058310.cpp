#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{

   int n,k,t;
   cin>>n>>k>>t;
   int h=0,s=0,i=1;
   while(s<=t)
   {
       s=n*i;
       if(s>t)
       {
           break;
       }
       h=k*i;
       i++;
   }
   cout<<h<<endl;
}
