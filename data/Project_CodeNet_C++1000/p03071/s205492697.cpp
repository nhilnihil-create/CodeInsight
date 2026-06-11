#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{

   int a,b;
   cin>>a>>b;
   int s=0;

   if(b<a){s=2*a-1;}
   else if(a==b){s=a+b;}
   else{s=2*b-1;}

   cout<<s<<endl;

}
