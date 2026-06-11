#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{
   int n;
   cin>>n;
   int c[n],v[n];
   for(int i=0;i<n;i++)
      cin>>v[i];
   for(int i=0;i<n;i++)
      cin>>c[i];
   double div[n];
   for(int i=0;i<n;i++)
      div[i] = (double)v[i]/c[i];
   int sum{};
   for(int i=0;i<n;i++)
   {
      if(div[i]>=1)
         sum += v[i] - c[i];
   }
   cout<<sum;
   return 0;
}
