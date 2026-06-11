#include <iostream>
using namespace std;

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   if(a==b && a!=c)
   {
       cout<<c<<endl;
   }
   else if(a==c && a!=b)
   {
       cout<<b<<endl;
   }
   else if(b==c && b!=a)
   {
       cout<<a<<endl;
   }

     return 0;
}