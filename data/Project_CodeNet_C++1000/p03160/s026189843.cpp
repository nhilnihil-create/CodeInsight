#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod 1000000009
using namespace std;
bool isprime(ll n)
{
    //if(n<2)
    //return false;
    if(n==1)
    return true;
    if(n==2 || n==3)
    return true;
    if(n%2==0)return false;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        return false;
        
    }
    return true;
}
int gcd(ll a,ll b)
{
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int lcm(ll a,ll b)
{
    return a*(b/gcd(a,b));
}
 set<ll> fac;
void allFactors(ll n)
{
   // set<ll> fac;
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            fac.insert(i);
            if(i!=n/i)
            {
                fac.insert(n/i);
               
            }
        }
    }
    //return fac.size();
}
bool threefactors(ll n)//when you have need of a no which is divisible by 1,itself,any other one no.
{
    ll p=sqrt(n);
    if(p*p==n)
    {
        if(isprime(p))
        return 1;
        else
        return 0;
    }
    else
    return 0;
}
unsigned int countSetBits(unsigned int n) //no. of 1's in a binary representation of a number
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
int main()
{
     IOS
     int testcases;
    // cin>>testcases;
     //while(testcases--)
     {
       
            int n;
            cin>>n;
           int h[n];
           for(int i=0;i<n;i++)
           {
               cin>>h[i];
           }
           ll dp[n];
           for(int i=0;i<n;i++)
           {
               dp[i]=mod;
           }
           dp[0]=0;
           for(int i=0;i<n;i++)
           {
               if(i+1<n)
               {
               if(dp[i+1]>0)
               dp[i+1]=min(dp[i+1],dp[i]+abs(h[i]-h[i+1]));
              // else
               //dp[i+1]=dp[i]+abs(h[i]-h[i+1]);
               }
               if(i+2<n)
               {
               if(dp[i+2]>0)
               dp[i+2]=min(dp[i+2],dp[i]+abs(h[i]-h[i+2]));
               //else
               //dp[i+2]=dp[i]+abs(h[i]-h[i+2]);
               }
           }
           cout<<dp[n-1];
     }
     return 0;
} 
//ascii of a=97
//ascii of A=65
//ascii of 0=48