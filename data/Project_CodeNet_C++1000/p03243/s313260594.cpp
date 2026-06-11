#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   for(int i=n;;i++)
   {
      int k=i;
      int a=k%10;
      k/=10;
      int b=k%10;
      k/=10;
      int c=k%10;
      k/=10;
      if(a==b&&b==c)
      {
          cout<<c<<b<<a<<endl;
          return 0;
      }
   }
}

