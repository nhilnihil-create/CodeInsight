#define ll long long
#define pi acos(-1.0)
#define Go "\n"
#define Afor(i,a,b) for( i=a;i<b;i++)
#define GCD __gcd
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll N,i,X=0,Y=0;
   cin>>N;
   ll V[N];
   ll C[N];
   Afor(i,0,N)
   {
       cin>>V[i];
   }
   Afor(i,0,N)
   {
       cin>>C[i];
       if(V[i]<=C[i])
       {
           V[i]=0;
           C[i]=0;
       }
   }
  ll p= accumulate(V,V+N,X);
   ll q= accumulate(C,C+N,Y);
    ll g=p-q;
    if(g<=0)
    {
        cout<<"0"<<"\n";
    }
    else
    {
        cout<<g<<"\n";
    }




}
