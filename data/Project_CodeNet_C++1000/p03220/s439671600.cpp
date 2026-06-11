#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   int n;
   cin>>n;
   double a, t, h;
   cin>>t>>a;
   int flag=0;
   double min_diff = DBL_MAX, diff;
   for (int i = 0; i < n; i++)
   {
       cin>>h;
       diff = a - t + 0.006 * h;
       if (abs(diff)<min_diff)
       {
           min_diff = abs(diff);
           flag = i;
       }
       
   }
   cout<<flag+1;
   
   return 0;
}
