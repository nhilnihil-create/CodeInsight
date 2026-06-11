#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   int n, t;
   cin>>n>>t;
   int ci, ti;
   int cost = INT32_MAX;
   int flag=0;
   for (int i = 0; i < n; i++)
   {
       cin>>ci>>ti;
       cost= ti<=t ? min(cost,ci) : cost;
       if (cost == ci)
       {
           flag = 1;
       }
       

   }
   if (flag == 0)
   {
       cout<<"TLE";
   }
   else
   {
       cout<<cost;
   }
   
   
   
   return 0;
}
