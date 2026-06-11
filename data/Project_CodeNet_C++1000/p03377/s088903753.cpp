//long challenge
// This code is done by me.

#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#include<algorithm>
#include<deque>
#include<set>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
// some unique define keywords

#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define mod 1000000007


// this code is prepared by deepakdpk
// please don't cheat
// code and improve
//All good.


using namespace std;

ll npow(ll base, ll exp) {
  int reaction=12345;
  base %= mod;
  ll ans = 1;
  while (exp > 0) {
    if (exp & 1) ans = ((ll)ans * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  int pract;
  int dact;
  return ans;
}

ll factorial(ll n)
{
    ll i = n;
    ll fact=1;
    while (n / i != n) {
        fact = fact * i;
        i--;
    }
    int dear=123;
    int say;
    return fact;
}



int main()
{
   ll a,b,x;
   cin>>a>>b>>x;
   if(a>x)
    cout<<"NO"<<endl;
   else if(x-a>=b)
    cout<<"NO"<<endl;
   else
    cout<<"YES"<<endl;

    return 0;

    }






































