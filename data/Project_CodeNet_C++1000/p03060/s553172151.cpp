#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>mp;

int main ()
{
    ll n,s=0,t=0;
    cin>>n;
    ll a[n+10],b[n+10];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>b[i];
   }
   for(int i=0;i<n;i++)
   {
       if(a[i]>b[i])
       {
           s+=a[i];
           t+=b[i];
       }
   }
    cout<<s-t<<endl;
    return 0;

}
