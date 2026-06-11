#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   ll n,m,C;
   cin>>n>>m>>C;
   ll arr[n+5][m+5]={0};
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>arr[i][j];
       }
   }
   ll x=0;
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
       ll cnt=0;
       ll c=0;
       for(int j=0;j<m;j++)
       {
           cnt+=arr[i][j]*arr[0][c];
           c++;


       }
       cnt+=C;
       if(cnt>0)
       {
           ans++;
       }
   }
   cout<<ans<<endl;

}

