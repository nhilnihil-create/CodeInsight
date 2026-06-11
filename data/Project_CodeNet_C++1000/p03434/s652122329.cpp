#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   ll n;
   cin>>n;
   ll arr[n+5]={0};
   ll alice=0;
   ll bob=0;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];

   }
   sort(arr,arr+n,greater<ll>());
   for(int i=0;i<n;i++)
   {
       if(i%2==0)
       {
           alice+=arr[i];
       }
       else
       {
           bob+=arr[i];
       }
   }
   cout<<alice-bob<<endl;

}
