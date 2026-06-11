#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n,y;
   cin>>n>>y;

   bool answered = false;
   for(int i=0;i<=n ;i++)
   {
       for(int j=0 ; j+i <= n ; j++)
       {
           if( y - (i* 10000 + j*5000) >=0 &&  (y == (i* 10000 + j*5000 + (n-i-j)*1000 ) )  )
           {
                cout<<i<<" "<<j <<" "<<n-i-j;
                answered = true;
                break;
           }
       }
       if( answered )
           break;
   }
   if( !answered )
   cout<<-1<<" "<<-1<<" "<<-1;

}