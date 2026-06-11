
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

int main()
{
    fastread();

   ll a,b,c;


cin>>a>>b>>c;


   for(ll i=0;i<10;i++)
   {
       cout<<(a*c)-b<<endl;
       c=(a*c)-b;
   }



}
