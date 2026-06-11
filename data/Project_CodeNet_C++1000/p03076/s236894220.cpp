#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   vector<int> arr(5);
   int mindig = 10;
   for(int i=0;i<5;i++)
   {
      cin>>arr[i];
      if(arr[i]%10)
         mindig = min(mindig,arr[i]%10);
   }
   ll sum = 0;
   for(int i=0;i<5;i++)
   {
      if(arr[i]%10 == 0)
         sum += arr[i];
      else
      {
         sum += (10 - arr[i]%10) + arr[i];
      }
   }
   sum -= 10 - mindig;
   cout<<sum;
   return 0;
}
