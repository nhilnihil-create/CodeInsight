#include<iostream>
using namespace std;

int main() 
{
   int a,b,ans,count=2;
   cin>>a>>b;
   while(count>0)
   {
      if(a>=b)
      {
        ans+=a;
        a--;
        count--;
      }
      else if(b>=a)
      {
          ans+=b;
          b--;
          count--;
      }
   }
   cout<<ans;
   return 0;
   
}