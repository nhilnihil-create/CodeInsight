#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   ll n;
   cin>>n;
   ll arr[5];
   ll mini=LONG_MAX;
   for(int i=0;i<5;i++)
   {
      cin>>arr[i];
      if(arr[i]<mini)
         mini = arr[i];
   }
   ll time = 4;
   if(n%mini == 0)
      time += n/mini;
   else
      time += n/mini + 1;
   cout<<time;
   return 0;
}
