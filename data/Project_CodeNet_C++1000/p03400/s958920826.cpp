#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
   int n, days, x, total = 0;

   cin >> n >> days >> x;

   vector<int> cc;

   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      cc.push_back(x);
   } 

   for(int i = 0; i < n; i++)
   {
      int d = 1, count = 1;
      d += cc[i];
      while(d<=days)
      {
         count++;
         d+=cc[i];
      }

      total += count;
   } 

   cout << total + x;
}