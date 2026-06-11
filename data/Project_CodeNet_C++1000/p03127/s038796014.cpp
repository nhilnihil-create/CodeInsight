#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)
#define M 100005
lli gcd(lli a,lli b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
   lli n,i;
   cin>>n;
   lli a[n];
   for(i=0;i<n;i++) cin>>a[i];
   lli g=a[0];
  // int mn=1000000000;
   for(i=1;i<n;i++)
   {

     g=__gcd(a[i],g);


   }
   cout<<g;

}




