#include<iostream>
#include<string.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int count=0;
   int len = s.length();
   for(int i=0; i<len; i++)
   {
       if(s[i]=='o'){count++;}
   }
   cout<<700+count*100;
}
