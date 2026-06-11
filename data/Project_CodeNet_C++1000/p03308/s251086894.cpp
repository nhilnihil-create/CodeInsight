#include<bits/stdc++.h>
using namespace std ;
int main ()
{
   long int n,x1=0,x,i,j;
   cin>>n;
   long int a[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(i=0;i<n;i++)
   {
       for(j=i;j<n;j++)
       {
           x=abs(a[i]-a[j]);
           x1=max(x1,x);
       }
   }
   cout<<x1;
}
