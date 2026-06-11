#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   int n, a;
   cin>>n;
   for (int i = n; i < 1000; i++)
   {
       if (i/100 == i%10 && i/100 == i/10%10)
       {
           cout<<i;
           break;
       }
       
   }
   
   return 0;
}
