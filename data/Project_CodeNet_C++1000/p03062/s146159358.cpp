#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{
   ll n;
   cin>>n;
   vector<ll> arr(n);
   ll sum{}, mini{LONG_MAX};
   ll negcount{};
   for(ll i=0;i<n;i++)
   {
      cin>>arr[i];
   }
   for(auto i = arr.begin(); i != arr.end();i++)
   {
      sum += abs(*i);
      mini = min(mini, abs(*i));
      if(*i < 0)
         negcount++;
   }
   if(negcount%2 != 0)
      sum -= 2*mini;
   cout<<sum;
   return 0;
}
