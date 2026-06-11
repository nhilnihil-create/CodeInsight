#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   string input;
   int count = 0,  ans = 0;

   cin >> input;

   for(int i = 0; i < input.length(); i++)
   {
      if(input[i] == 'A' || input[i] == 'T' || input[i] == 'G' || input[i] == 'C')
      {
         count++;
      }

      else
      {
         count = 0;
      }
      

      ans = max(ans,count);
   }

   cout << ans;
}