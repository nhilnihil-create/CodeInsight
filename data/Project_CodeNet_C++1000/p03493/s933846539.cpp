#include<iostream>
using namespace std;
int main()
{
   int a,s,count=0;;
   cin>>a;
   while(a!=0)
   {
       s=a%10;
       a=a/10;
       if(s==1){count++;}
   }
   cout<<count;
}