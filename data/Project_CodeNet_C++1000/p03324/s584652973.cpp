#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
   int d,n;
   cin>>d>>n;
   if( d==0 )
   {
       if( n!= 100)
           cout<<n;
       else cout<<101;
   }
   if( d==1)
   {
       if( n!= 100)
           cout<<n*100;
       else cout<<10100;
   }
   if( d== 2)
   {
       if( n!= 100)
       cout<<n*10000;
       else cout<<1010000;
   }
}