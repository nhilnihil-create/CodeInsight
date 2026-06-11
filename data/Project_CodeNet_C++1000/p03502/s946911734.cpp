#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{   int t,sum=0;
   cin>>t;
   int temp=t;
 while(temp!=0)
 {
        sum+=(temp%10);
        temp/=10;
 
 }
 if(t%sum==0)cout<<"Yes";
 else
 {
 cout<<"No";}
 return 0;
   }
 
 