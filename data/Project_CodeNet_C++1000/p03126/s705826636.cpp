#include <bits/stdc++.h>
using namespace std;
int main() {
   int n,m,k,a;
  int  mp[31]={0};
   cin>>n>>m;
  

   for(int i=0;i<n;i++)
   {
       cin>>k;
       for(int j=0;j<k;j++)
       {
           cin>>a;
           mp[a]++;

       }
   }
   int count=0;
   for(int i=0;i<=31;i++)
   {
       if(mp[i]==n)
       {
           count++;
       }
   }
   cout<<count<<endl;
}
