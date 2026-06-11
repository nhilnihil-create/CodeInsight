#include <iostream>
using namespace std;

int main()
{
   int a,b,c,d;
   cin >>a;
   cin >>b;
   c=(a*b);
   d=(c%2);
   if (d==0)
   {
     cout << "Even"<< endl;
   }
   else 
   {
     cout << "Odd"<< endl;
   }
   return 0;
}