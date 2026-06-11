#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n;
   cin>>n;
   map<ll,ll> m;
   for(int i=0;i<n;i++)
   {
       ll temp ;
       cin>>temp;
       m[temp] ++;
   }
   ll ans =0;
   auto it = m.begin() ;
   for( ;it!= m.end() ;it++)
   {
       if( it->first > it->second )
       {
           ans += it->second;
       }
       else ans += (it->second - it->first );
   }
   cout<<ans;
}