#include<iostream>
using namespace std;

int main() 
{
   char s[11];
   cin>>s;
   int prevcount=0,i;
   int count=0;
   int arrSize = sizeof(s)/sizeof(s[0]);
   for(i=0;i<arrSize;i++)
   {
       if(s[i]=='A'||s[i]=='T'||s[i]=='C'||s[i]=='G')
       {
           count++;
       }
       else
       {
           if(count>prevcount)
           {prevcount=count;}
           count=0;
       }
   }
   if(count>prevcount)
   {prevcount=count;}
   
   
   cout<<prevcount;
   return 0;
   
}