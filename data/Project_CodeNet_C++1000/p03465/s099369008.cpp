#include<bits/stdc++.h>
#define pb push_back 
#define ff first
#define ss second
#define MOD 1000000007
#define ll long long int
#define P pair<int,int>
 
using namespace std;
 
 
ll add(ll x,ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}
 
ll mul(ll x,ll y)
{
    return (x * 1ll * y) % MOD;
}
 
ll binpow(ll x,ll y)
{
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
ll inv(ll x)
{
    return binpow(x, MOD - 2);
}
 
 
ll divide(ll x,ll y)
{
    return mul(x, inv(y));
}


bitset<10000000> bits;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   int t=1;
   //cin>>t;

   bits.set(0);
   
   while(t--)
   {
         int n;
         cin>>n;

         int sum=0;
         for(int i=0;i<n;i++)
         {
             int y;
             cin>>y;
             sum+=y;
             bits=((bits<<y)|bits);
         }

         for(int i=(sum+1)/2;;i++)
         {
           if(bits.test(i))
           {
             cout<<i;
             return 0;
           }
         }
        
   }
   
   return 0;
}