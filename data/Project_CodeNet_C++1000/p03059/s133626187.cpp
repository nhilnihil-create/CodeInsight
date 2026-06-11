#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{
   int a,b,t;
   cin>>a>>b>>t;
   int count{};
   int sec = a;
   while(sec<=t)
   {
      count++;
      sec += a;
   }
   cout<<count*b;
   return 0;
}
