#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
   long long n, x, total = 0;

   cin >> n >> x;

   vector<long long> hp;

   for(int i = 0; i < n; i++)
   {
      long x;
      cin >> x;
      hp.push_back(x);
   }

   sort(hp.begin(),hp.end());

   for(int i = 0; i < n; i++)
   {
      total = total + hp[i];
   }

   if(total < x)
      cout << n - 1;
   else if(total == x)
   {
      cout << n;
   }

   else
   {
      long long i = 0;
      while(x < total)
      {
         total = total - hp[n-1-i];
         i++;
      }

      cout << n - i;
   }
   
   
}